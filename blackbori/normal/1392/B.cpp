#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[202020];
ll n, k, t, i, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for(; t --; ){
		cin >> n >> k;
		for(i = 1; i <= n; i ++){
			cin >> A[i];
		}
		k = (k & 1)? 1 : 2;
		for(; k --; ){
			m = *max_element(A + 1, A + n + 1);
			for(i = 1; i <= n; i ++){
				A[i] = m - A[i];
			}
		}
		for(i = 1; i <= n; i ++){
			cout << A[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}