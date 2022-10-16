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

const int INF = 1e9 + 7, N = 1e5 + 7;

bool win(ll s, ll e) {
	if(e & 1) return (s & 1) == 0;
	if(s * 2 > e) return (e - s) & 1;
	e /= 2;
	if(s * 2 > e) return 1;
	return win(s, e / 2);
}

bool lose(ll s, ll e) {
	if(2 * s > e) return 1;
	return win(s, e / 2);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	bool can_a = 0, can_b = 1, can_a1 = 1, can_b1 = 0;
	for(int i = 0; i < n; i++) {
		ll s, e;
		cin >> s >> e;
		bool can_win = win(s, e);
		bool can_lose = lose(s, e);
		bool nw_can_a = (can_win && can_b) || (!can_win && can_a);
		bool nw_can_b = (can_lose && can_b) || (!can_lose && can_a);
		bool nw_can_a1 = (can_lose && can_a1) || (!can_lose && can_b1);
		bool nw_can_b1 = (can_win && can_a1) || (!can_win && can_b1);
		can_a = nw_can_a, can_b = nw_can_b, can_a1 = nw_can_a1, can_b1 = nw_can_b1;
	}
	cout << can_a << ' ' << can_a1 << endl;

}