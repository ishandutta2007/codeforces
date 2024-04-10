#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

deque<char> d;
string s;
void solve(int i, int j) {
	if(j < i) {
		return;
	} else if(i == j) {
		d.push_back(s[i]);
	} else if(i+1 == j) {
		if(s[i] == s[j]) {
			d.push_back(s[i]);
			d.push_back(s[j]);
		} else
			d.push_back(s[i]);
	} else if(i+2 == j) {
		solve(i+1, j-1);
		if(s[i] == s[j]) {
			d.push_front(s[i]);
			d.push_back(s[j]);
		}
	} else {
		for(int a = 0; a < 2; ++a) {
			for(int b = 0; b < 2; ++b) {
				if(s[i+a] == s[j-b]) {
					solve(i+a+1, j-b-1);
					d.push_front(s[i+a]);
					d.push_back(s[j-b]);
					return;
				}
			}
		}
	}
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	int n = s.size();
	solve(0, n-1);
	while(d.size()) {
		cout << d.front();
		d.pop_front();
	}
	cout << '\n';
}