#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	reverse (s.begin(), s.end());
	string t = "", r = "";
	for (int i = 0; i < x; i++){
		t += s[i];
		r += '0';
	}
	r[y] = '1';
	int ans = 0;
	for (int i = 0; i < x; i++){
		if(t[i] != r[i])
			ans ++;
	}
	cout << ans;
}