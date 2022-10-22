/* 	* In the name of GOD 
 	* Thanks God */
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
		string s;
		cin >> s;
		int n = s.size();
		int x = 0, y = 0;
		vector <int> v;
		for (int i = 0; i < n; i++){
			if (s[i] == '0'){
				x++;
			}else{
				y++;
			}
		}
		cout << (min(x, y) % 2 ? "DA" : "NET") << endl;
	}
}