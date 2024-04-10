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

const int M = 1e9 + 7, N = 2e5 + 7;

int p[N], a[N], pre[N][20], h[N][20], pw[N];
int n;
string s;

int go(int pos, int cnt) {
	int cur = 0, ret = 0;
	for(int i=19;i>=0;i--) {
		if(cnt >> i & 1) {
			ret = h[pos][i] + ret * pw[cur] % M;
			ret %= M;
			pos = pre[pos][i] - 1;
			cur += 1 << i;
		}
	}
	return ret;
}

signed main()
{
	IO_OP;
	pw[0] = 1;
	for(int i=1;i<N;i++)
		pw[i] = pw[i-1] * 3 % M;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(pw, pw+N, rng);
	cin >> n >> s;
	for(int i=1;i<=n;i++) a[i] = s[i-1] - '0';
	for(int i=1;i<=n;i++)
		p[i] = a[i] + p[i-1];
	for(int i=1;i<=n;i++) {
		pre[i][0] = pre[i-1][0];
		if(a[i] == 0) pre[i][0] = i;
	}
	for(int i=1;i<=n;i++) {
		h[i][0] = ((i - pre[i][0]) & 1) + 1;
	}
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			if(pre[i][j-1] > 0)
				pre[i][j] = pre[pre[i][j-1]-1][j-1];
	for(int j=1;j<20;j++) {
		for(int i=1;i<=n;i++) {
			h[i][j] = h[pre[i][j-1]-1][j-1] * pw[j-1] % M + h[i][j-1];
			h[i][j] %= M;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout << h[i][0] << " ";
	// cout << endl;
	int q;
	cin >> q;
	while(q--) {
		int x, y, len;
		cin >> x >> y >> len;
		if(p[x+len-1]-p[x-1] != p[y+len-1]-p[y-1]) {
			cout << "NO" << endl;
			continue;
		}
		int cnt = len - (p[x+len-1]-p[x-1]);
		int h1 = go(x+len-1, cnt);
		int h2 = go(y+len-1, cnt);
		// debug(h1);
		// debug(h2);
		if(h1 == h2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

}