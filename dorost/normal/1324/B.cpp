#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int32_t main(){
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		bool f = false;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			for (int j = 0; j < i - 1; j++){
				if (a[i] == a[j]){
					f = true;
					break;
				}
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
}