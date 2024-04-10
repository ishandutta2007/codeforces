#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, m, i, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	m = 0;
	for(i = 0; i < n; i ++){
		cin >> b;
		cout << b + m << " ";
		if(b > 0) m += b;
	}
	cout << "\n";
	
	return 0;
}