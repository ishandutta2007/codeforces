/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			string t;
			for (int k = 0; k < n; k++){
				if (k < i || k > j){
					t += s[k];
				}
			}
			if (t == "CODEFORCES")
				return cout << "YES", 0;
		}
	}
	cout << "NO";
}