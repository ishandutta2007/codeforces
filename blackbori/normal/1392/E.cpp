#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[33][33], C[66][66], L[33][33];
ll n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll q, i, j, k, c, s, x, y;

	cin >> n;

	for(i = C[0][0] = 1; i <= n + n; i ++){
		for(j = C[i][0] = 1; j <= n + n; j ++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	for(j = n - 1; j >= 1; j --){
		for(i = 2; i <= n; i ++){
			A[i][j] = C[n - i + 1 + n - j - 1][n - i + 1] + L[i - 1][j + 1] - L[i][j + 1];
			L[i][j] = L[i][j + 1] + A[i][j];
		}
	}

	for(i = 1; i <= n; i ++){
		for(j = 1; j <= n; j ++){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	cout.flush();

	cin >> q;
	
	for(; q --; ){
		cin >> k;
		x = y = 1; cout << 1 << " " << 1 << "\n";
		for(i = 2; i < n + n; i ++){
			if(k < C[n - x + n - y - 1][n - x]){
				y ++;
			}
			else{
				k -= C[n - x + n - y - 1][n - x];
				x ++;
			}
			cout << x << " " << y << "\n";
		}
		cout.flush();
	}

	return 0;
}