#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'





struct dsu_save {
    int v, rnkv,  u, rnku;
	pair<int, int>compv, compu;
    dsu_save() {}

    dsu_save(int _v, int _rnkv,pair<int, int> _compv,  int _u, int _rnku, pair<int, int> _compu)
        : v(_v), rnkv(_rnkv), compv(_compv), u(_u), rnku(_rnku), compu(_compu) {}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk;
    vector<pair<int, int>>comp;
    stack<dsu_save> op;
	int tot;
    dsu_with_rollbacks() {}

    dsu_with_rollbacks(int n) {
        p.resize(n);
        rnk.resize(n);
        comp.resize(n);
        for (int i = 0; i <n; i++) {
            p[i] = i;
            rnk[i] = 0;
            if(i<=300000){
            	comp[i]={1, 0};
            }
            else{
            	comp[i]={0, 1};
            }
        }
        tot=0;
    }

    int find_set(int v) {
        return (v == p[v]) ? v : find_set(p[v]);
    }

    bool unite(int v, int u) {
        v = find_set(v);
        u = find_set(u);
        if (v == u)
            return false;
        
        if (rnk[v] > rnk[u])
            swap(v, u);
        op.push(dsu_save(v, rnk[v], comp[v], u, rnk[u], comp[u]));
        p[v] = u;
        tot-=(comp[u].f*comp[u].s);
        tot-=(comp[v].f*comp[v].s);
        comp[u]={comp[u].f+comp[v].f, comp[u].s+comp[v].s};
        tot+=(comp[u].f*comp[u].s);
        if (rnk[u] == rnk[v])
            rnk[u]++;
        return true;
    }

    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();
        op.pop();
    	
        p[x.v] = x.v;
        rnk[x.v] = x.rnkv;
        comp[x.v] = x.compv;
        p[x.u] = x.u;
        rnk[x.u] = x.rnku;
        comp[x.u]=x.compu;
        tot+=(comp[x.u].f*comp[x.u].s);
        tot+=(comp[x.v].f*comp[x.v].s);
        tot-=(comp[x.u].f+comp[x.v].f)*(comp[x.u].s+comp[x.v].s);
    }
};

struct query {
    int v, u;
    bool united;
    query(int _v, int _u) : v(_v), u(_u) {
    }
};

struct QueryTree {
    vector<vector<query>> t;
    dsu_with_rollbacks dsu;
    int T;

    QueryTree() {}

    QueryTree(int _T, int n) : T(_T) {
        dsu = dsu_with_rollbacks(n);
        t.resize(4 * T + 4);
    }

    void add_to_tree(int v, int l, int r, int ul, int ur, query& q) {
        if (ul > ur)
            return;
        if (l == ul && r == ur) {
            t[v].push_back(q);
            return;
        }
        int mid = (l + r) / 2;
        add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
        add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
    }

    void add_query(query q, int l, int r) {
        add_to_tree(1, 0, T - 1, l, r, q);
    }

    void dfs(int v, int l, int r, vector<int>& ans) {
        for (query& q : t[v]) {
            q.united = dsu.unite(q.v, q.u);
        }
        if (l == r)
            ans[l] = dsu.tot;
        else {
            int mid = (l + r) / 2;
            dfs(2 * v, l, mid, ans);
            dfs(2 * v + 1, mid + 1, r, ans);
        }
        for (query q : t[v]) {
            if (q.united)
                dsu.rollback();
        }
    }

    vector<int> solve() {
        vector<int> ans(T);
        dfs(1, 0, T - 1, ans);
        return ans;
    }
};







main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	vector<pair<pair<int, int>, pair<int, int>>>v;
	map<pair<int, int>, int>m;
	for(int i=1; i<=q; i++){
		int x, y;
		cin>>x>>y;
		if(m[{x, y}]==0){
			m[{x, y}]=i;
		}
		else{
			v.pb({{x, y}, {m[{x, y}], i-1}});
			m[{x, y}]=0;
		}
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		if((*it).s==0){
			continue;
		}
		v.pb({it->first, {it->second, q}});
	}
	QueryTree qt(q, 600005);
	for(auto u:v){
		qt.add_query(query(u.f.f, u.f.s+300000), u.s.f-1, u.s.s-1);
	}
	vector<int>ans=qt.solve();
	for(auto u:ans){
		cout<<u<<" ";
	}
	return 0;
}