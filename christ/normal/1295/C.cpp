// Problem : C. Obtain The String
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/C
// Memory Limit : 256.000000 MB
// Time Limit : 1000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
string s,t;
vector<int> inds[100];
int main () {
	io();
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> s >> t;
		for (int i = 0; i < 100; i++) inds[i].clear();
		for (int i = 0; i < s.length(); i++) {
			inds[s[i]-'a'].push_back(i);
		}
		bool bad = 0;
		for (int i = 0; i < t.length(); i++) {
			if (inds[t[i]-'a'].empty()) {
				printf ("-1\n");
				bad = 1;
                break;
			}
		}
		if (!bad) {
			int w = -1, ret = 1;
			for (int i = 0; i < t.length(); i++) {
				auto it = upper_bound(all(inds[t[i]-'a']),w);
				if (it == inds[t[i]-'a'].end()) {
					++ret;
					--i;
					w = -1;
					continue;
				}
				w = *it;
			}
			printf ("%d\n",ret);
		}
	}
	return 0;
}