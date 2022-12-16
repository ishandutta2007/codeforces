#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main () {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int amt = 1;
	int pairs = 0;
	stack<char> st;
	for(auto& c : s) {
		if(!st.empty() && st.top() == c) {
			++pairs;
			st.pop();
		} else {
			st.push(c);
		}
	}
	cout << ((pairs&1) ? "Yes" : "No") << endl;
	return 0;
}