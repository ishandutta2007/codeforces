#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A[333][333];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, i, j, s, x, f;

	cin >> t;

	for(; t --; ){
		cin >> n >> m; f = 0;
		for(i = 1; i <= n; i ++){
			for(j = 1; j <= m; j ++){
				cin >> x; s = 0;
				if(i > 1) s ++;
				if(i < n) s ++;
				if(j > 1) s ++;
				if(j < m) s ++;
				if(s < x) f = 1;
				else A[i][j] = s;
			}
		}
		if(f) cout << "NO\n";
		else{
			cout << "YES\n";
			for(i = 1; i <= n; i ++){
				for(j = 1; j <= m; j ++){
					cout << A[i][j] << " ";
				}
				cout << "\n";
			}
		}
	}	

	return 0;
}