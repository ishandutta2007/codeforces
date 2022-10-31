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

set<int> re;
vector<int> st;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ans = 0, nxt = 1;
	for(int i = 0; i < 2*n; ++i) {
		string cmd;
		cin >> cmd;
		if(cmd == "add") {
			int a;
			cin >> a;
			st.pb(a);
		} else {
			if(!st.empty() && st.back() != nxt) {
				++ans;
				for(int i = 0; i < st.size(); ++i)
					re.insert(st[i]);
				st.clear();
			}
			if(st.back() == nxt) st.pop_back();
			else re.erase(nxt);
			++nxt;
		}
	}
	cout << ans << "\n";	
}