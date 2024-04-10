/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
string s[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			s[i] += '1';
		}
		s[n] = "";
		for (int i = 0; i < n + 1; i++){
			s[n] += '1';
		}
		bool f = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (s[i][j] == '0')
					continue;
				if (s[i][j + 1] == '0' && s[i + 1][j] == '0')
					f = false;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
}