#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A[202020];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i, n, f;

	cin >> t;

	for(; t --; ){
		cin >> n;
		for(i = 1; i <= n; i ++){
			cin >> A[i];
		}
		f = 0;
		for(i = 1; i <= n; i ++){
			if(A[i] != A[1]) f = 1;
		}
		if(f == 1) cout << "1\n";
		else cout << n << "\n";
	}

	return 0;
}