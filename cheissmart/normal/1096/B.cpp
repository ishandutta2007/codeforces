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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353;

signed main()
{
	IO_OP;

	int n;
	string s;
	cin >> n >> s;
	int ans = 1;
	for(char c = 'a'; c <= 'z'; c++) {
		int fst = INF, lst=-INF, has = 0;
		for(int i=0;i<n;i++) {
			if(s[i] != c) {
				fst = min(i, fst);
				lst = max(i, lst);
			} else {
				has = 1;
			}
		}
		if(has) {
			ans += ((fst+1) * (n-lst) % M + M - 1);
		}
	}

	ans %= M;
	cout << ans << endl;
}