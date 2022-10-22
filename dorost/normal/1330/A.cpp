#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		int a[n];
		map <int, bool> mp;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]] = true;
		}
		for (int i = 1; i <= 310; i++){
			if (mp[i] == false){
				mp[i] = true;
				x --;
				if (x == 0)
					break;
			}
		}
		for (int i = 1; i <= 311; i++){
			if (!mp[i]){
				cout << i - 1 << endl;
				break;
			}
		}
	}
}