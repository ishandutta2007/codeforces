#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e3 + 10;

int n, m, x[MAXN], dist[MAXN];
pii z[MAXN];
ll d[2][MAXN];
pair<ll, int> q[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> x[i];
	sort(x, x + n);

	for (int i = 0; i < m; i++)
		cin >> z[i].F >> z[i].S;
	sort(z, z + m);

	bool cur = 0;
	for (int i = 0; i < n; i++)
		if (z[0].S < i+1)
			d[cur][i + 1] = 1e16;
		else
			d[cur][i + 1] = d[cur][i] + abs(x[i] - z[0].F);

	for (int j = 1; j < m; j++, cur = !cur){
		for (int i = 0; i < MAXN; i++)
			d[!cur][i] = 1e16;
		d[!cur][0] = 0;

		for (int i = 0; i < n; i++)
			dist[i] = abs(x[i] - z[j].F);

		int h = 0, t = 0;
		ll temp = 0;
		q[t++] = {0ll, 0};
		for (int i = 0; i < n; i++){
			temp += dist[i];
			while (t-h && q[t - 1].F+temp >= d[cur][i+1]) t--;

			q[t++] = {d[cur][i + 1]-temp, i+1};
			if (i+1 - z[j].S > q[h].S) h++;

			d[!cur][i+1] = q[h].F+temp;
		}
	}

	if (d[cur][n] < 1e15)
		cout << d[cur][n] << "\n";
	else
		cout << "-1\n";
	return 0;
}