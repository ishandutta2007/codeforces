#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 5;

string tob(int x) { // reversed binary
	if(x == 0) return "0";
	string s;
	while(x){
		s += (char)(x%2+'0');
		x /= 2;
	}
	return s;
}

int a[N], vis[200];
vector<pi> es;
string b[N];
vi G[N];

int bfs(int u, int v) {
	memset(vis, 0xff, sizeof vis);
	vi q({u});
	vis[u] = 0;
	for(int i=0;i<q.size();i++) {
		if(q[i] == v) return vis[v];
		for(int e:G[q[i]]) {
			if(es[e].F != -1) {
				int j = es[e].F ^ es[e].S ^ q[i];
				if(vis[j] == -1) {
					vis[j] = vis[q[i]]+1;
					q.PB(j);
				}
			}
		}
	}
	return INF;
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi v;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t) v.PB(t);
	}
	n = v.size();
	for(int i=0;i<n;i++)
		a[i] = v[i];
	for(int i=0;i<n;i++)
		b[i] = tob(a[i]);
	if(n > 120) {
		cout << 3 << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			for(int k=0;k<j;k++)
				if((a[i]&a[j]) && (a[j] & a[k]) && (a[i]&a[k])) {
					cout << 3 << endl;
					return 0;
				}
	for(int i=0;i<n;i++) {
		for(int j=0;j<i;j++) {
			for(int k=0;k<b[i].size()&&k<b[j].size();k++) {
				if(b[i][k] == '1' && b[j][k] == '1') {
					es.EB(i, j);
					G[i].PB(es.size()-1);
					G[j].PB(es.size()-1);
					break;
				} 
			}
		}
	}
	int ans = INF;
	for(int i=0;i<es.size();i++) {
		pi tmp = es[i];
		es[i] = {-1, -1};
		ans = min(ans, 1+bfs(tmp.F, tmp.S));
		es[i] = tmp;
	}
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}