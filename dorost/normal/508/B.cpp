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
	bool f = false, h = false;
	for (char c : s){
		if ((c - '0') % 2 == 0)
			f = true;
		if (c != s[0])
			h = true;
	}
	if (!f || !h)
		return cout << -1 << endl, 0;
	int an = -1;
	int an2 = -1;
	bool fh = true;
	for (int i = 0; i < s.size(); i++){
		char c = s[i];
		if ((c - '0') % 2)
			continue;
		if (c < s[s.size() - 1]){
			if (fh){
				an = i;
				fh = false;
			}
		}else{
			an2 = i;
		}
	}
	string t = s;
	string ans = "";
	if (an != -1)
		swap(s[s.size() - 1], s[an]), ans = max(ans, s);
	if (an2 != -1)
		swap(t[t.size() - 1], t[an2]), ans = max(ans, t);
	cout << ans << endl;
}