/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		string s;
		string t = "abacaba";
		cin >> n >> s;
		bool ans = false;
		int an = 0;
		for (int i = 0; i < n - 6; i++){
			bool f = true;
			for (int j = 0; j < 7; j++){
				if (s[i + j] != t[j])
					f =false;
			}
			if (f)
				an ++;
		}
		vector <int> v;
		string as;
		if (an == 1){
			for (int i = 0; i < n; i++){
				if (s[i] == '?')
					s[i] = 'e';
			}
			ans = true;
			as = s;
			goto G;
		}
		for (int i = 0; i < n - 6; i++){
			bool f = true;
			for (int j = 0; j < 7; j++){
				if (s[i + j] != t[j] && s[i + j] != '?')
					f = false;
			}
			if (f){
				v.push_back (i);
			}
		}
		for (int i = 0; i < v.size(); i++){
			string g = s;
			int x = 0;
			for (int j = 0; j < 7; j++){
				if (g[v[i] + j] == '?')
					g[v[i] + j] = t[j];
			}
			for (int i = 0; i < n; i++){
				if (g[i] == '?')
					g[i] = 'u';
			}
			for (int k = 0; k < n - 6; k++){
				bool f = true;
				for (int l = 0; l < 7; l++){
					if (g[k + l] != t[l])
						f = false;
				}
				if (f)
					x ++;
			}
			if (x == 1){
				ans = true;
				as = g;
				break;
			}
		}
		G :
		if (ans){
			cout << "Yes\n";
			cout << as << '\n';
		}else{
			cout << "No\n";
		}
	}
}