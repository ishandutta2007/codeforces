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

	array<int, 6> a;
	for(int i = 0; i < 6; i++) cin >> a[i];
	sort(ALL(a));
	int n;
	cin >> n;
	vi b(n);
	for(int i = 0; i < n; i++) cin >> b[i];
	set<array<int, 3>> s;
	for(int i = 0; i < n; i++) s.insert({b[i] - a[5], i, 5});
	int ans = INF;
	while(true) {
		ans = min(ans, (*s.rbegin())[0] - (*s.begin())[0]);
		auto tt = *s.begin();
		s.erase(tt);
		if(tt[2] == 0) break;
		int i = tt[1], j = tt[2] - 1;
		s.insert({b[i] - a[j], i, j});
	}
	cout << ans << endl;

}