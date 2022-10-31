#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MN = 2*(4e5+4e5+20);
vvi g;
int SD;
vi dnum,dlow,S,vs,sv;
bitset<MN> tv;
vi res,ord;
int ctr,nsc,tord;
void addor(int a, int b) {
	g[(a+SD)%(2*SD)].push_back(b);
	g[(b+SD)%(2*SD)].push_back(a);
}
void tsort(int u) {
	for(int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if(!tv[v]) {
			tv.set(v);
			tsort(v);
		}
	}
	if(ord[sv[u]] == -1) {
		ord[sv[u]] = tord++;
	}
}
void scc(int u) {
	dlow[u] = dnum[u] =ctr++;
	S.push_back(u);
	vs[u] = 1;
	for(int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if(dnum[v] == -1) {
			scc(v);
		}
		if(vs[v]) {
			dlow[u] = min(dlow[u],dlow[v]);
		}
	}
	if(dlow[u] == dnum[u]) {
		nsc++;
		while(1) {
			int v = S.back();
			sv[v] = nsc;
			S.pop_back();vs[v] = 0;
			if(v == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	nsc = ctr = tord = 0;
	int n,p,M,m;
	cin >> n >> p >> M >> m;
	M += 10;
	SD = p+M+1;
	g.assign(2*SD,vi());
	dnum.assign(g.size()+2,-1);
	dlow.assign(g.size()+2,0);
	vs.assign(g.size()+2,0);
	sv.assign(g.size()+2,-1);
	ord.assign(g.size()+2,-1);
	for(int i=0;i<M;i++) {
		addor(p+i,SD+p+i+1);
	}
	for(int i=0;i<n;i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		addor(a,b);
	}
	for(int i=0;i<p;i++) {
		int a,b;
		cin >> a >> b;
		addor(i+SD,p+a);
		addor(i+SD,SD+p+b+1);
	}
	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		addor(a+SD,b+SD);
	}
	for(int i=0;i<g.size();i++) {
		if(dnum[i] == -1) {scc(i);}
	}
	bool poss = true;
	for(int i=0;i<SD;i++) {
		//cout << sv[i] << " / " << sv[i+SD] << '\n';
		if(sv[i] == sv[SD+i]) {
			poss = false;
		}
	}
	if(!poss) {
		cout << -1 << '\n';
		return 0;
	}
	for(int i=0;i<g.size();i++) {
		if(!tv[i]) {
			tv.set(i);
			tsort(i);
		}
	}
	for(int i=0;i<p;i++) {
		if(ord[sv[i]] < ord[sv[SD+i]]) {
			res.push_back(i+1);
		}
	}
	int tt = -1;
	for(int i=0;i<=M;i++) {
		if(ord[sv[p+i]] > ord[sv[SD+p+i]]) {
			tt = i-1;break;
		}
	}
	cout << res.size() << " " << tt << '\n';
	for(int i=0;i<res.size();i++) {
		if(i > 0) {cout << " ";}
		cout << res[i];
	}
	cout << '\n';
}