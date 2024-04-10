#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

struct cmp {
	bool operator () (pii A, pii B) {
		if (A.Y - A.X != B.Y - B.X) return A.Y - A.X > B.Y - B.X;
		return A.X < B.X;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int all1 = count(all(s), '1');
		int ans = -x;
		fop (i,0,k) {
			string t;
			int tmp = 0;
			for (int j = 0; i + j * k < n; j++) {
				t += s[i + j * k];
				if (s[i + j * k] == '1') tmp++;
			}
			vector <int> pre(t.length() + 1, 0);
			deque <int> dq;
			dq.push_back(0);
			fop (i,1,t.length() + 1) {
				pre[i] = pre[i - 1] + (t[i - 1] == '1' ? 1 : -1);
				while (dq.size() and pre[dq.back()] > pre[i]) dq.pop_back();
				dq.push_back(i);
				ans = max(ans, pre[i] - pre[dq.front()]);
			}
		}
		cout << all1 - ans << endl;
	}
}