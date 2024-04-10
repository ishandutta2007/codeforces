#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, i;

	cin >> t;

	for(; t --; ){
		cin >> n;
		if(n == 1) cout << "-1\n";
		else{
			cout << "2";
			for(i = 1; i < n; i ++){
				cout << "3";
			}
			cout << "\n";
		}
	}

	return 0;
}