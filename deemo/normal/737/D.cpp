#include<bits/stdc++.h>

using namespace std;

const int C = 130;
const int MAXN = 5000 + 10;

int n, a[MAXN], p[MAXN], d[C][C][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], p[i + 1] = p[i] + a[i];
	
	for (int i = C - 4; i; i--)
		for (int j = i; ~j; j--)
			for (int v = n; ~v; v--){
				int u = v + j;
				if (v + u > n)	continue;
				
				if (v + u + i <= n){
					d[i][j][v] = (p[v + i] - p[v]) - (v + u + i + i <= n?(p[n - u] - p[n - u - i]):0) + d[i][j][v + i];
					if (v + u + i + i < n)
						d[i][j][v] = min(d[i][j][v], (p[v + i] - p[v]) - (p[n - u] - p[n - u - i - 1]) + d[i+1][j+1][v + i]);
					if (v + u + i + 1 <= n){
						int ret = -1e9;
						ret = (p[v + i+1] - p[v]) - (v + u + i + 1 + i + 1 <= n?(p[n - u] - p[n - u - i-1]):0) + d[i+1][j][v + i+1];
						if (v + u + i + 1 + i + 2 <= n)
							ret = min(ret, (p[v + i+1] - p[v]) - (p[n - u] - p[n - u - i-2]) + d[i+2][j+1][v + i+1]);
						d[i][j][v] = max(d[i][j][v], ret);
					}
				}
			}
	
	cout << d[1][0][0] << "\n";
	return 0;
}