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
		int mp[256] = {};
		for (int i = 0; i < n; i++){
			mp[s[i]] ++;
		}
		char an = 'X';
		if (mp['S'] >= mp['R'] && mp['S'] >= mp['P']){
			an = 'R';
		}else if (mp['R'] >= mp['S'] && mp['R'] >= mp['P']){
			an = 'P';
		}else{
			an = 'S';
		}
		for (int i = 0; i < n; i++)
			cout << an;
		cout << endl;
	}
}