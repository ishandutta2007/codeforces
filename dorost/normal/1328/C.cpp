#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t; 
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans[n] = {};
		bool f = true;
		for (int i = 0; i < n; i++){
			if (!f){
				cout << s[i];
				continue;
			}
			if (s[i] == '0'){
				cout << 0;
			}
			if (s[i] == '1'){
				f = false;
				ans[i] = 1;
				cout << '0';
			}
			if (s[i] == '2'){
				ans[i] = 1;
				cout << 1;
			}
		}
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << ans[i];
		cout << endl;
	}
}