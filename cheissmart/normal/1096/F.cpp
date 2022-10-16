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

const int INF = 1e9 + 7, N = 2e5 + 7, M = 998244353, inv2 = 499122177;

int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int bit[N];
void add(int pos, int val = 1) {
	for(; pos < N; pos += pos & -pos)
		bit[pos] = (bit[pos] + val) % M;
}
int qry(int pos) {
	int ret = 0;
	for(; pos; pos -= pos & -pos)
		ret += bit[pos];
	return ret % M;
}

int go(vi v) {
	int ans = 0;
	for(int i = (int)v.size() - 1; i >= 0; i--) {
		ans += qry(v[i]);
		add(v[i]);
	}
	return ans % M;
}

int a[N];
 
signed main()
{
	IO_OP;
	int n, cnt = 0;
	cin >> n;
	vi v;
	set<int> yes;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] != -1) v.PB(a[i]), yes.insert(a[i]);
		else cnt++;
	}
	int inv_cnt = qpow(cnt, M - 2);

	int ans = go(v);
	memset(bit, 0, sizeof bit);
	for(int i = 1; i <= n; i++) {
		if(yes.count(i) == 0)
			add(i);
	}
	int rcnt = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] != -1) {
			ans += rcnt * qry(a[i]) % M * inv_cnt % M;
		} else {
			rcnt++;
		}
	}
	int lcnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] != -1) {
			ans += lcnt * (cnt - qry(a[i])) % M * inv_cnt % M;
		} else {
			lcnt++;
		}
	}
	ans += cnt * (cnt - 1) % M * inv2 % M * inv2 % M;
	ans %= M;
	cout << ans << endl;
}