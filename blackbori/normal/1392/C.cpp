#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[202020];
ll n, k, t, i, m, s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for(; t --; ){
		cin >> n; m = 0; s = 0;
		for(i = 1; i <= n; i ++){
			cin >> A[i];
			s += max(0ll, m - A[i]);
			m = A[i];
		}
		cout << s << "\n";
	}

	return 0;
}