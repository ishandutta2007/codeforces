#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = SZ(s);
	int one = count(ALL(s), '1');
	auto ok = [&] (int tt) {
		if(one <= tt) return true;
		// one - tt <= kept1
		// kept 0 <= tt
		int cnt0 = 0, cnt1 = 0;
		for(int i = 0, j = 0, k = 0; i < n; i++) {
			cnt0 += s[i] == '0';
			cnt1 += s[i] == '1';
			while(cnt0 > tt && j <= i) {
				cnt0 -= s[j] == '0';
				j++;
			}
			while(k + 1 <= i && cnt1 - (s[k] == '1') >= one - tt) {
				cnt1 -= (s[k] == '1');
				k++;
			}
			if(j <= i && k <= i && cnt0 <= tt && cnt1 >= one - tt && j <= k)
				return true;
		}
		return false;
	};
	int lb = 0, rb = n;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		if(ok(mb)) rb = mb - 1;
		else lb = mb + 1;
	}
	cout << lb << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}