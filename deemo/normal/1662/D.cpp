#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using ll = long long;

const char nl = '\n';
const int MX = 2e5 + 10;

string go(string s) {
	string t;
	for(char ch : s) {
		if(ch != 'B') {
			t += ch;
		}
	}
	string ans;
	for(char ch : t) {
		ans += ch;
		if(sz(ans) >= 2 && ans.back() == ans.end()[-2]) {
			ans.pop_back();
			ans.pop_back();
		}
	}
	return ans;
}

void solve() {
	string s, t;
	cin >> s >> t;
	bool ok = true;
	for(char ch : {'A', 'B', 'C'}) {
		ok = ok && count(all(s), ch) % 2 == count(all(t), ch) % 2;
	}
	if(ok && go(s) == go(t)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int te = 1;
	cin >> te;
	while(te--) {
		solve();
	}
}