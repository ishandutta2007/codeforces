#include <bits/stdc++.h>

using namespace std;
using piii = tuple <int, int, int>;

vector <piii> E;
int D[222][222];
int n, m, a;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, j, k, u, v, b;

	cin >> n >> m;

	for(i = 1; i <= n; i ++){
		for(j = 1; j <= n; j ++){
			D[i][j] = 1e6;
		}
		D[i][i] = 0;
	}

	for(i = 1; i <= m; i ++){
		cin >> u >> v >> b;
		if(!b) D[u][v] = D[v][u] = 1;
		else D[u][v] = 1, D[v][u] = -1;
		E.emplace_back(u, v, b);
	}

	for(i = 1; i <= n; i ++){
		for(j = 1; j <= n; j ++){
			for(k = 1; k <= n; k ++){
				if(D[j][k] > D[j][i] + D[i][k]){
					D[j][k] = D[j][i] + D[i][k];
				}
			}
		}
	}
	a = -1;
	for(i = 1; i <= n; i ++){
		bool f = 0;
		for(auto &[u, v, b]: E){
			if(b && D[i][u] + 1 != D[i][v]) f = 1;
			if(abs(D[i][u] - D[i][v]) != 1) f = 1;
		}
		if(D[i][i] != 0) f = 1;
		if(f) continue;
		int t = *max_element(D[i], D[i] + n) - *min_element(D[i], D[i] + n);
		if(a < t) a = t, k = i;
	}

	if(a == -1) cout << "NO\n";
	else{
		cout << "YES\n" << a << "\n";
		int t = *min_element(D[k], D[k] + n);
		for(i = 1; i <= n; i ++) cout << D[k][i] - t << " ";
		cout << "\n";
	}

	return 0;
}