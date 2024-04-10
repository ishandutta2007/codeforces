#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

struct vert {
	int good,tot,ind;
	vert(int g, int b, int i):good(g),tot(b),ind(i){}
	bool operator<(const vert& v) const {
		ll b = 1LL*good*(v.tot) - 1LL*v.good*(tot);
		if(b == 0) return ind < v.ind;
		return b < 0;
	}
};

const int N = 1e5+5;
set<vert> Q;
bool c[N]={};
int g[N]={};
vvi G;

vi order;
vi A,B;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) {
		int q;
		cin >> q;
		c[q] = true;
	}
	G = vvi(n+1);
	for(int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i = 1; i <= n; ++i) {
		if(c[i]) continue;
		g[i]=0;
		for(int v : G[i]) {
			if(!c[v]) ++g[i];
		}
		Q.insert(vert(g[i],G[i].size(),i));
	}
	// cout << "hi" << endl;
	while(Q.size()) {
		// cout << Q.size() << endl;
		vert v = *Q.begin();
		Q.erase(Q.begin());
		order.pb(v.ind);
		A.pb(v.good);
		B.pb(v.tot);
		c[v.ind] = true;
		for(int w : G[v.ind]) {
			if(c[w]) continue;
			Q.erase(vert(g[w],G[w].size(),w));
			Q.insert(vert(--g[w],G[w].size(),w));
		}
	}
	int best = 0;
	for(int i = 1; i < A.size(); ++i) {
		if(1LL*A[i]*B[best] > 1LL*A[best]*B[i]) {
			best = i;
		}
	}
	cout << A.size() - best << "\n";
	for(int i = best; i < A.size(); ++i) {
		cout << order[i] << " ";
	}
	cout << "\n";

	return 0;
}