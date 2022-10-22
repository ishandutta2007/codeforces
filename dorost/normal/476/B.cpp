/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	vector <string> v = {""};
	string s, t;
	cin >> s >> t;
	int n = s.size(), ans = 0;
	for (int i = 0; i < n; i++){
		ans += (s[i] == '+' ? 1 : -1);
	}
	for (int i = 0; i < n; i++){
		if (t[i] == '?'){
			int m = v.size();
			for (int j = 0; j < m; j++){
				v.push_back(v[j]);
				v[j] += '+';
				v[v.size() - 1] += '-';
			}
		}else{
			for (int j = 0; j < v.size(); j++){
				v[j] += t[i];
			}
		}
	}
	int num = 0;
	for (int i = 0; i < v.size(); i++){
		string r = v[i];
		int an = 0;
		for (int i = 0; i < n; i++){
			an += (r[i] == '+' ? 1 : -1);
		}
		if (an == ans)
			num++;
	}
	cout << fixed << setprecision(100);
	cout << (0.0 + (ld)num) / ld(v.size());
}