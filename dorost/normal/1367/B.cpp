#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i], a[i] %= 2;
		int nu1 = 0, nu2 = 0;
		for (int i = 0; i < n; i++){
			if (i % 2 != a[i]){
				if (i % 2)
					nu1++;
				else
					nu2++;
			}
		}
		cout << (nu1 != nu2 ? -1 : nu1) << endl;
	}
}