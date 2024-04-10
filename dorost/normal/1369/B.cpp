/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
bool f[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		string s;
		cin >> n >> s;
		vector <pair <char, int>> v;
		int x = 0;
		bool h = false;
		for (int i = 1; i < n; i++){
			if (s[i] != s[i - 1]){
				v.push_back({s[i - 1], x + 1});
				x = 0;
			}else{
				x++;
			}
			if (s[i] == '0' && s[i - 1] == '1'){
				h = true;
			}
		}
		v.push_back({s[n - 1], x + 1});
		for (int i = 0; i < n; i++){
			f[i] = true;
//			cout << v[i].F << ' ' << v[i].S << endl;
		}
		if (h)
			cout << 0;
		for (int i = 0; i < v.size(); i++){
			if (v[i].F == '0' && i == 0){
				for (int j = 0; j < v[i].S; j++){
					cout << 0;
				}
			}else if (v[i].F == '1' && i == v.size() - 1){
				for (int j = 0; j < v[i].S; j++){
					cout << 1;
				}
			}
		}
		cout << endl;
	}
}