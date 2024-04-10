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

const int INF = 1e9 + 7, N = 1003;

vi G[N];

int qry(int u, int v) {
	cout << "? " << u << " " << v << endl;
	int ret;
	cin >> ret;
	return ret;
}

bool vis[N];
vi s;

void dfs1(int u, int p = 0) {
	s.PB(u);
	for(int v:G[u]) if(v != p && !vis[v]) {
		dfs1(v, u);
	}
}

void ans(int u) {
	cout << "! " << u << endl;
	exit(0);
}

void go(int root) {
	s.clear();
	dfs1(root);
	if(s.size() == 1) ans(s[0]);
	else if(s.size() == 2) ans(qry(s[0], s[1]));
	int cur=-1;
	for(int u:s) {
		int cnt = 0;
		for(int v:G[u]) if(!vis[v]) cnt++;
		if(cnt >= 2) {
			if(cur == -1) cur = u;
			else {
				if(cnt%2==0) cur = u;
			}
		}
	}
	vi ch;
	for(int v:G[cur]) if(!vis[v]) {
		ch.PB(v);
	}
	if(ch.size()&1) {
		int nxt = cur;
		for(int i=0;i+1<ch.size();i+=2) {
			int ret = qry(ch[i], ch[i+1]);
			if(ret != cur) {
				nxt = ret;
				break;
			}
		}
		int ret = qry(cur, ch.back());
		if(ret != cur) {
			nxt = ret;
		}
		if(nxt == cur) ans(cur);
		vis[cur] = 1;
		go(nxt);
	} else {
		int nxt = cur;
		for(int i=0;i<ch.size();i+=2) {
			int ret = qry(ch[i], ch[i+1]);
			if(ret != cur) {
				nxt = ret;
				break;
			}
		}
		if(nxt == cur) ans(cur);
		vis[cur] = 1;
		go(nxt);
	}
}

signed main()
{
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	go(1);	
}