/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 3e5;
ll n, a[mx], s[mx];
multiset<ll> st;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		st.insert(a[i] + 1 - i);
	}
	for (ll i = 0; i < n; ++i) {
		auto it = st.end();
		it--;
		if (i == 0)
			s[i] = max(0LL, (*it) + i);
		else
			s[i] = max(s[i - 1], (*it) + i);
		st.erase(st.find(a[i] + 1 - i));
	}
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += s[i] - 1 - a[i];
	}
	cout << sum << endl;
}