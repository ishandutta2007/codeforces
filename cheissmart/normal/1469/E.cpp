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

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N], b[N];

int nxt[N * 21][2], sz[N * 21];

signed main()
{
	IO_OP;

	int q;
	cin >> q;
	while(q--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		for(int i = 0; i < n; i++) {
			a[i + 1] = s[i] - '0';
			b[i + 1] = a[i + 1] + b[i];
		}
		string ans;
		int lst = min(k, 20);
		for(int i = 0; i < k - lst; i++)
			ans.PB('0');
		int root = 0, cnt = 1;
		auto add = [&] (vi& t) {
			int u = root;
			for(int i:t) {
				if(nxt[u][i] == 0) {
					nxt[u][i] = cnt++;
				}
				u = nxt[u][i];
			}
			sz[u] = 1;
		};
		for(int i = 1; i + k - 1 <= n; i++) {
			int l = i, r = i + k - 1;
			int cutr = r - lst;
			if(b[cutr] - b[l - 1] != cutr - l + 1) continue;
			vi t;
			for(int j = cutr + 1; j <= r; j++) t.PB(a[j]);
			assert((int)t.size() == lst);
			add(t);
		}
		for(int i = cnt; i >= 0; i--) {
			if(nxt[i][0]) sz[i] += sz[nxt[i][0]];
			if(nxt[i][1]) sz[i] += sz[nxt[i][1]];
		}
		if(sz[0] == (1 << lst)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			int u = root;
			for(int i = lst; i >= 1; i--) {
				if(u == -1) {
					ans += '0';
					continue;
				}
				int sz0 = (nxt[u][0] ? sz[nxt[u][0]] : 0);
				int sz1 = (nxt[u][1] ? sz[nxt[u][1]] : 0);
				if(sz1 == (1 << (i - 1))) {
					ans += '1';
					if(nxt[u][0]) u = nxt[u][0];
					else u = -1;
				} else {
					ans += '0';
					if(nxt[u][1]) u = nxt[u][1];
					else u = -1;
				}
			}
			cout << ans << endl;
		}

		for(int i = 0; i <= cnt; i++) {
			nxt[i][0] = nxt[i][1] = 0;
			sz[i] = 0;
		}
	}

}