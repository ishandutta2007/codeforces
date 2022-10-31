#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string shift(string s) {
	return s.substr(1,s.size()-1) + s[0];
}

set<string> S;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		S.insert(s);
		s = shift(s);
	}
	cout << S.size() << "\n";
	
	return 0;
}