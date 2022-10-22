#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n] = {}, b[n] = {};
		map <int, int> mp;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			while (x % 2 == 0){
				x /= 2;
				a[i]++;
			}
			b[i] = x;
		}
		bool f[n] = {};
		for (int i = 0; i < n; i++){
			if (a[i] == 0)
				continue;
			if (mp[b[i]] == 0)
				f[i] = true;
			mp[b[i]] = max(mp[b[i]], a[i]);
		}
//		for (int i = 0; i < n; i++)
//			cout << b[i] << ' ' << a[i] << endl;
//		cout << endl;
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (f[i]){
				ans += mp[b[i]];
//				cout << mp[b[i]] << ' ';
			}
		}
		cout << endl;
		cout << ans << endl;
	}
}