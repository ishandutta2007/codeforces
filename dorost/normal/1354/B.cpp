/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
bool h[3];
int an[3];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size();
		if (n < 3){
			cout << 0 << endl;
			continue;
		}
		int mn = n + 100;
		vector <pair <char, pair <int, int>>> v;
		for (int i = 0; i < n; i++){
			int x = i;
			while (i < n && s[i] == s[x]){
				i++;
			}
			v.push_back({s[x], {x, i - 1}});
			i--;
		}
		for (int i = 0; i < v.size(); i++){
			int in1 = v[i].S.F, in2 = v[i].S.S;
			if (in1 == 0 || in2 == n - 1)
				continue;
			if (s[in1 - 1] != s[in1] && s[in2 + 1] != s[in1 - 1] && s[in1] != s[in2 + 1])
				mn = min(in2 - in1 + 3, mn);
		}
		if (mn == n + 100)
			cout << 0 << endl;
		else
			cout << mn << endl;
	}
}