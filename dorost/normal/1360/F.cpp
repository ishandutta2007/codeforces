/*  * In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 11;
string a[N];

int diff (string s, string t){
	int a = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != t[i]){
			a++;
		}
	}
	return a;
}

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool H = true;
		for (int i = 0; i < m && H; i++){
			for (int j = 0; j < 26 && H; j++){
				string t = a[0];
				t[i] = j + 'a';
				bool f = true;
				for (int k = 1; k < n && H; k++){
					if (diff(a[k], t) > 1)
						f = false;
				}
				if (f){
					cout << t << endl;
					H = false;
				}
			}
		}
		if (H)
			cout << -1 << endl;
	}
}