#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 10 + 1;

int n, m, k, adj[MAXN];
ll d[1<<MAXN][1<<MAXN], t[1<<MAXN][1<<MAXN], f[1<<MAXN][1<<MAXN], g[2][1<<MAXN];

void get(int mask){
	memset(g, 0, sizeof(g));
	bool cur = 0;
	for (int a = mask; a; a=a-1&mask)	g[cur][a] += d[mask][a];
	
	for (int i = 0; i < n; i++, cur = !cur)
		for (int j = 0; j < 1<<n; j++){
			g[!cur][j] = g[cur][j];
			if (j>>i&1)
				g[!cur][j] += g[cur][j ^ 1<<i];
		}

	for (int i = 0; i < 1<<n; i++)
		f[mask][i] = g[cur][i];
}

int main(){
	cin >> n >> m >> k;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a] |= 1<<b;
		adj[b] |= 1<<a;
		d[1<<a|1<<b][1<<a|1<<b] = 1;
	}
	for (int i = 0; i < n; i++)	d[1<<i][1<<i] = 1;

	t[0][0] = 1;
	for (int a = 1; a < 1<<n; a++)
		for (int b = 1; b < 1<<n; b++)
			if (!(a&b)){
				int v = __builtin_ctz(a&-a);
				for (int c = b; c; c = c-1&b)
					if ((c & adj[v]) == c)
						t[a][b] += t[a ^ 1<<v][b ^ c];
			}

	for (int mask = 1; mask < (1<<n); mask++){
		int cnt = __builtin_popcount(mask);

		if (cnt > 2){
			for (int m2 = mask-1&mask; m2; m2 = m2-1&mask){
				int j = __builtin_popcount(m2);
				if (j < 2)	continue;
	
				int temp = mask ^ m2;
				for (int a = temp; a; a=a-1&temp)
					d[mask][m2] += t[a][m2] * f[temp][a];
			}
		}
		get(mask);
	}

	ll ans = 0;
	for (int ms = 0; ms < 1<<n; ms++)
		if (__builtin_popcount(ms) == k)
			ans += d[(1<<n)-1][ms];
	cout << ans << "\n";
	return 0;
}