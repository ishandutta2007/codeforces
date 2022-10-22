//Just wish that I didn't feel like there was something I missed..

#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

#define F first
#define S second
#define up pu

const int MAXN = 400 + 5;

int n, m, mat[MAXN][MAXN];
int d[MAXN][MAXN], nxt[MAXN], pu[MAXN], e[MAXN][MAXN];
vector<pair<int, int>>	vec[MAXN * MAXN];
pair<int, int>	q[MAXN * MAXN];

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.S ^ b.S)
		return a.S < b.S;
	return a.F < b.F;
}

void init(int row){
	for (int i = 1; i < MAXN * MAXN; i++){
		int t = 0;
		for (int j = (int)vec[i].size() - 1; ~j; j--){
			auto x = vec[i][j];
			if (x.F > row)	continue;
			while (t && q[t - 1].F < x.F)	t--;
			if (t)
				d[x.F][x.S] = q[t - 1].S;
			else
				d[x.F][x.S] = m;

			if (d[x.F][x.S] == x.S)
				up[x.S] = max(up[x.S], x.F + 1);
			q[t++] = x;
		}

		t = 0;
		for (int j = 0; j < vec[i].size(); j++){
			auto x = vec[i][j];
			if (x.F > row)	continue;
			while (t && q[t - 1].F < x.F)	t--;
			if (t)
				e[x.F][x.S] = q[t - 1].S;
			else
				e[x.F][x.S] = -1;
			q[t++] = x;
		}
	}

	for (int i = row - 1; ~i; i--)
		for (int j = 0; j < m; j++)
			d[i][j] = min(d[i][j], d[i + 1][j])
				, e[i][j] = max(e[i][j], e[i + 1][j]);

	nxt[m - 1] = m;
	for (int j = m - 2; ~j; j--)
		nxt[j] = min(nxt[j + 1], d[row][j]);
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			scanf("%d", &mat[i][j]);
			vec[mat[i][j]].push_back({i, j});
		}
	for (int i = 1; i < MAXN * MAXN; i++)
		sort(vec[i].begin(), vec[i].end(), cmp);

	int ans = 1;
	for (int i = 0; i < n; i++){
		fill(up, up + m, 0);
		init(i);

		for (int j = m - 1; ~j; j--){
			int cur = pu[j];
			if (j + 1 < m)
				for (int w = i; ~w; w--)
					d[w][j] = min(d[w][j], d[w][j + 1]);

			ans = max(ans, i - cur + 1);
			for (int w = j+1; w < nxt[j]; w++){
				while (d[cur][j] <= w || e[cur][w] >= j)	cur++;
				ans = max(ans, (w - j + 1) * (i - cur + 1));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}