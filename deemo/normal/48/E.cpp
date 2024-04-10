#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 200 + 5;

int h0, t0, mx, n, m, th[MAXN], gg[MAXN], hth[MAXN], tgg[MAXN];
int sz, vis[MAXN][MAXN], d[MAXN][MAXN], lv[MAXN][MAXN];
pair<int, int>	sec[MAXN * MAXN], q[MAXN * MAXN];

bool valid(int a, int b){return a + b <= mx;}

void go(int a, int b){
	if (a + b > mx)	return;
	if (vis[a][b] == 1){
		printf("Draw\n");
		exit(0);
	}
	if (vis[a][b])	return;

	vis[a][b] = 1;
	for (int i = 0; i < n && i + 1 <= a; i++){
		pair<int, int> u(max(0, a - i - 1), b);
		u.F += th[i], u.S += gg[i];
		go(u.F, u.S);
	}

	for (int i = 0; i < m && i + 1 <= b; i++){
		pair<int, int> u(a, max(0, b - i - 1));
		u.F += hth[i], u.S += tgg[i];
		go(u.F, u.S);
	}

	vis[a][b] = 2;
	sec[sz++] = {a, b};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h0 >> t0 >> mx;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> th[i] >> gg[i];
	cin >> m;
	for (int i = 0; i < m; i++)	cin >> hth[i] >> tgg[i];

	{
		memset(lv, 63, sizeof(lv));
		lv[h0][t0] = 0;
		int h = 0, t = 0;
		q[t++] = {h0, t0};
		while (h < t){
			auto v = q[h++];
			for (int i = 0; i < n && i + 1 <= v.F; i++){
				pair<int, int> u(max(0, v.F - i - 1), v.S);
				u.F += th[i], u.S += gg[i];
				if (valid(u.F, u.S) && lv[u.F][u.S] > lv[v.F][v.S] + 1)
					lv[u.F][u.S] = lv[v.F][v.S] + 1, q[t++] = u;
			}

			for (int i = 0; i < m && i + 1 <= v.S; i++){
				pair<int, int> u(v.F, max(0, v.S - i - 1));
				u.F += hth[i], u.S += tgg[i];
				if (valid(u.F, u.S) && lv[u.F][u.S] > lv[v.F][v.S] + 1)
					lv[u.F][u.S] = lv[v.F][v.S] + 1, q[t++] = u;
			}
		}
	}

	if (lv[0][0] < 1e7){
		printf("Ivan\n");
		printf("%d\n", lv[0][0]);
		return 0;
	}

	go(h0, t0);

	int ans = 1;
	for (int w = sz - 1; ~w; w--){
		int a = sec[w].F, b = sec[w].S;
		for (int i = 0; i < n && i + 1 <= a; i++){
			pair<int, int> u(max(0, a - i - 1), b);
			u.F += th[i], u.S += gg[i];
			if (u.F + u.S <= mx)
				d[u.F][u.S] = max(d[u.F][u.S], d[a][b] + 1);
		}

		for (int i = 0; i < m && i + 1 <= b; i++){
			pair<int, int> u(a, max(0, b - i - 1));
			u.F += hth[i], u.S += tgg[i];
			if (u.F + u.S <= mx)
				d[u.F][u.S] = max(d[u.F][u.S], d[a][b] + 1);
		}
		ans = max(ans, d[a][b] + 1);
	}

	printf("Zmey\n");
	printf("%d\n", ans);
	return 0;
}