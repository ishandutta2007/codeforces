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

const int INF = 1e9 + 7, N = 3e5 + 7;

struct AC{
	static const int N = 1e6 + 7; // maximum number of nodes
	static const int S = 26; // sigma
	int ch[N][S], last[N], fail[N], val[N], cnt;
	multiset<int> tt[N];
	AC() {
		memset(ch, 0, sizeof ch);
		cnt = 1;
	}
	int idx(char c) { return c - 'a'; }
	int insert(string s, int v = 1) {
		int u = 0;
		for(char c : s) {
			int ci = idx(c);
			if(!ch[u][ci]) {
				val[cnt] = 0;
				ch[u][ci] = cnt++;
			}
			u = ch[u][ci];
		}
		val[u] = v;
		tt[u].insert(0);
		return u;
	}
	void build_fail() {
		queue<int> q;
		fail[0] = 0;
		for(int c = 0;c < S;c++) {
			int u = ch[0][c];
			if(u) fail[u] = 0, q.push(u), last[u] = 0;
		}
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int c = 0;c < S;c++) {
				int v = ch[u][c];
				if(!v) continue;
				q.push(v);
				int r = fail[u];
				while(r && !ch[r][c]) r = fail[r];
				fail[v] = ch[r][c];
				last[v] = val[fail[v]] ? fail[v] : last[fail[v]];
			}
		}
	}
	int go(string s) {
		int j = 0, ans = -1;
		for(int i=0;i<s.size();i++) {
			int c = idx(s[i]);
			while(j && !ch[j][c]) j = fail[j];
			j = ch[j][c];
			if(val[j]) ans = max(ans, find(i, j));
			else if(last[j]) ans = max(ans, find(i, last[j]));
		}
		return ans;
	}
	int find(int i, int j) { // find node j end at i
		int mx = -1;
		if(j) {
			// cout << i << ": " << j << endl;
			mx = max(*tt[j].rbegin(), find(i, last[j]));
		}
		return mx;
	}
} ac;

string s[N];
int pos[N], cur[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		pos[i] = ac.insert(s[i]);
	}
	ac.build_fail();
	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i, x;
			cin >> i >> x;
			i--;
			int j = pos[i];
			ac.tt[j].erase(ac.tt[j].find(cur[i]));
			cur[i] = x;
			ac.tt[j].insert(cur[i]);
		} else {
			string t;
			cin >> t;
			cout << ac.go(t) << '\n';
		}
	}
	
}