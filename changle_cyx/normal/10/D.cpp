#include <bits/stdc++.h>

using namespace std; 

#define range(x) x.begin(), x.end()

typedef pair<int, int> pii; 

const int MaxN = 500 + 5; 
//orzczk
int n, m; 
int a[MaxN], b[MaxN]; 
vector<int> all; 

int nxt[MaxN][MaxN << 1]; 

int f[MaxN][MaxN]; 
pii g[MaxN][MaxN]; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0); 

	cin >> n; 
	for (int i = 1; i <= n; ++i) cin >> a[i], all.push_back(a[i]); 
	cin >> m; 
	for (int i = 1; i <= m; ++i) cin >> b[i], all.push_back(b[i]); 	

	sort(range(all)); 
	all.resize(unique(range(all)) - all.begin()); 

	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(range(all), a[i]) - all.begin(); 
	for (int i = m; i >= 1; --i) {
		b[i] = lower_bound(range(all), b[i]) - all.begin(); 

		for (int k = 0; k < (int)all.size(); ++k) nxt[i][k] = nxt[i + 1][k]; 
		nxt[i][b[i]] = i; 
	}

	a[0] = b[0] = -1; 
	for (int i = n; i >= 0; --i)
		for (int j = m; j >= 0; --j)
			if (a[i] == b[j]) {
				f[i][j] = 1, g[i][j] = {n + 1, m + 1}; 

				for (int k = i + 1, w; k <= n; ++k)
					if (a[k] > a[i] && (w = nxt[j + 1][a[k]]) && f[k][w] + 1 > f[i][j]) {
						f[i][j] = f[k][w] + 1; 
						g[i][j] = {k, w}; 
					}
				
				// cerr << i << ' ' << j << ':' << f[i][j] << '\n'; //
			}
	
	cout << f[0][0] - 1 << '\n'; 

	pii cur = g[0][0]; 
	while (cur.first <= n) {
		cout << all[a[cur.first]] << " \n"[f[cur.first][cur.second] == 1]; 
		cur = g[cur.first][cur.second]; 
	}

	return 0; 
}