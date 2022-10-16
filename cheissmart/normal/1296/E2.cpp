#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int n;
int ans[N];
string s;

bool ok(int m) {
	set<pair<char, int>> st;
	for(int i=0;i<m;i++) {
		st.insert(MP('a', i));
	}
	for(int i=0;i<n;i++) {
		char c = s[i];
		auto it = st.upper_bound(MP(c, INF));
		if(it == st.begin()) return false;
		--it;
		ans[i] = it -> S;
		st.erase(it);
		st.insert(MP(c, ans[i]));
	}
	return true;
}

signed main()
{
	IO_OP;

	cin >> n >> s;	
	int l = 1, r = n;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m - 1;
		else l = m + 1;
	}
	cout << l << endl;
	ok(l);
	for(int i=0;i<n;i++)
		cout << ans[i] + 1 << " ";
}