/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 256;
int cnt[M];

int32_t main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[(int)s[i]] ++;
	}
	cout << min({cnt[(int)'B'], cnt[(int)'l'], cnt[(int)'b'], cnt[(int)'s'], cnt[(int)'r'], cnt[(int)'a'] / 2, cnt[(int)'u'] / 2});
}