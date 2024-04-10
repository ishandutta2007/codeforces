#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'


const int M=3e5+5;

struct SegTree{
	vector<pair<int, int>> T;
	vector<int> lazy;
	int N, MX;
	void clear(int n, int mx){
		N=n;
		MX=mx;
		T.assign(4*N, {mx, 1});
		lazy.assign(4*N, 0);
	}
	void build(int v, int tl, int tr){
		if(tl==tr){
			T[v]={1e9, 1};
		}
		else{
			int tm=(tl+tr)/2;
			int lf=v<<1;
			int rt=lf^1;
			build( lf, tl, tm);
			build( rt, tm+1, tr);
			if(T[lf].f==T[rt].f){
				T[v]={T[lf].f, T[lf].s+T[rt].s};
			}
			else{
				T[v]=min(T[lf], T[rt]);
			}
		}
	}
	void push(int v){
		int lf=(v<<1);
		int rt=lf^1;
		T[lf].f=(T[lf].f+lazy[v]);
		lazy[lf]=(lazy[lf]+lazy[v]);
		T[rt].f=(T[rt].f+lazy[v]);
		lazy[rt]=(lazy[rt]+lazy[v]);
		lazy[v]=0;
	}
	void update(int v, int tl, int tr, int l, int r, int val){
		if(l>r || tl>r || tr<l){
			return;
		}
		if(l<=tl && tr<=r){
			T[v].f=T[v].f+val;
			lazy[v]=(lazy[v]+val);
		}
		else{
			if(tl==tr){
				return;
			}
			push(v);
			int tm=(tl+tr)>>1;
			int lf=(v<<1);
			int rt=lf^1;
			update(lf, tl, tm, l, r, val);
			update(rt, tm+1, tr, l, r, val);
			if(T[lf].f==T[rt].f){
				T[v]={T[lf].f, T[lf].s+T[rt].s};
			}
			else{
				T[v]=min(T[lf], T[rt]);
			}
		}
	}
	pair<int, int> query(int v, int tl, int tr, int l, int r){
		if(l>r){
			return {1e9, 0};
		}
		if(l<=tl && tr<=r){
			return T[v];
		}
		push(v);
		int tm=(tl+tr)>>1;
		int lf=(v<<1);
		int rt=lf^1;
		auto u1=query(lf, tl, tm, l, min(r, tm));
		auto u2=query(rt, tm+1, tr, max(l, tm+1), r);
		if(u1.f==u2.f){
			return {u1.f, u1.s+u2.s};
		}
		else{
			return min(u1, u2);
		}
	}
	pair<int, int> q(int l, int r){
		return query(1, 0, N-1, l, r);
	}
	void u(int l, int r, int val){
		update(1, 0, N-1, l, r, val);
	}
}st;

struct hld{
	int n, t;
	vector<int>sz, in, out, root, par, depth;
	vector<vector<int>>g;
	SegTree tree;
	void dfs_sz(int v=0, int p=0){
		sz[v]=1;
		for(auto &u: g[v]){
			if(u==p){
				continue;
			}
			dfs_sz(u, v);
			sz[v]+=sz[u];
			if(sz[u]>sz[g[v][0]]){
				swap(u, g[v][0]);
			}
		}
	}
	void dfs_hld(int v=0, int p=0){
		in[v]=t++;
		par[v]=p;
		depth[v]=depth[p]+1;
		for(auto u:g[v]){
			if(u==p){
				continue;
			}
			root[u]=(u==g[v][0] ? root[v]:u);
			dfs_hld(u, v);
		}
		out[v]=t;
	}
	void pre(vector<vector<int>> &v){
		g=v;
		n=v.size();
		t=0;
		sz.assign(n, 0);
		in.assign(n, 0);
		out.assign(n, 0);
		root.assign(n, 0);
		par.assign(n, 0);
		depth.assign(n, 0);
		depth[0]=-1;
		dfs_sz();
		dfs_hld();
		tree.clear(n, 1e9);
	}
	template <class BinaryOperation>
	void processPath(int u, int v, BinaryOperation op){
		for(; root[u]!=root[v]; v=par[root[v]]){
			if(depth[root[u]]>depth[root[v]]){
				swap(u, v);
			}
			op(in[root[v]], in[v]);
		}
		if(depth[u]>depth[v]){
			swap(u, v);
		}
		op(in[u], in[v]);
	}
	void modifyPath(int u, int v, const int &value){
		processPath(u, v, [this,&value](int l, int r){tree.u(l, r, value);});}
		
	void modifySubtree(int u, const int &value){
		tree.u(in[u], out[u]-1, value);
	}
	pair<int, int> queryPath(int u, int v){
		pair<int,int> res={1e9, 0};
		auto add=[](pair<int, int> &a, const pair<int, int> &b){
			if(a.f==b.f){
				int val=b.s;
				a={a.f, a.s+val};
			}
			else{
				a=min(a, b);
			}
		};
		processPath(u, v, [this,&res,&add](int l, int r){add(res, tree.q(l, r));});
		return res;
	}
	pair<int, int> querySubtree(int u){
		return tree.q(in[u], out[u]-1);
	}
};
int n;
vector<vector<int>>a1;
vector<vector<int>>a2;
hld hl;
int ans=0;

void dfs(int v, int p){

	
	hl.modifyPath(v, v, -1e9);
	
	hl.modifyPath(0, v, 1);
	
	auto u=hl.querySubtree(0);
	
	if(u.f==1){
		ans=max(ans, u.s);
	}
	for(auto u:a1[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
	}
	hl.modifyPath(v, v, 1e9);
	hl.modifyPath(0, v, -1);
}

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		a1.clear();
		a2.clear();
		a1.resize(n+1);
		a2.resize(n+1);
		for(int i=1; i<n; i++){
			int p;
			cin>>p;
			p--;
			a1[i].pb(p);
			a1[p].pb(i);
		}
		for(int i=1; i<n; i++){
			int p;
			cin>>p;
			p--;
			a2[i].pb(p);
			a2[p].pb(i);
		}
		hl.pre(a2);
	
		dfs(0, -1);
		
		cout<<ans<<endl;
	}
	return 0;
}