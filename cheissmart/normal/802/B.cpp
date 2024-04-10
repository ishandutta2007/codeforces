#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	vi a(n), lst(n, INF), nxt(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for(int i = n - 1; i >= 0; i--) {
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	set<pi> who;
	set<int> cur;
	int cost = 0;
	for(int i = 0; i < n; i++) {
		if(cur.count(a[i])) {
			who.erase({i, a[i]});
			who.insert({nxt[i], a[i]});
			continue;
		}
		cost++;
		if(who.size() == k) {
			int x = who.rbegin() -> S;
			who.erase(*who.rbegin());
			cur.erase(x);
		}
		cur.insert(a[i]);
		who.insert({nxt[i], a[i]});
	}
	cout << cost << '\n';
}