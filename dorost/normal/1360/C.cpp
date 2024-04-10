/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N], mp[N], m[2];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i <= N; i++){
			mp[i] = 0;
		}
		m[0] = 0;
		m[1] = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
			m[a[i] % 2] ++;
		}
		if (m[0] % 2 == 0 && m[1] % 2 == 0){
			cout << "YES\n";
			continue;
		}
		bool f = false;
		for (int i = 2; i <= N; i++){
			if (mp[i] && mp[i - 1]){
				f = true;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
}