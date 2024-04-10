#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pvv pair<vector<int>, vector<int>>
#define pii pair<int, int>
#define f first
#define s second

const int N = 300005;

int q, xid[N], yid[N];
pvv nodes[N*20]; int top;
stack<pair<pii, pii>> st;
vector<pii> tree[N<<2];
map<pii, int> lst; ll ans;

bool unite(pii p){
    int xx = xid[p.f], yy = yid[p.s];
    if(xx==-1 && yy==-1){
        st.push({{-1, top}, {1, 1}});
        xid[p.f] = yid[p.s] = top;
        nodes[top++] = {{p.f}, {p.s}};
        ++ans; return 1;
    }
    if(xx==-1){
        st.push({{-1, yy}, {1, 0}});
        ans -= 1ll*nodes[yy].f.size()*nodes[yy].s.size();
        nodes[yy].f.push_back(p.f);
        ans += 1ll*nodes[yy].f.size()*nodes[yy].s.size();
        xid[p.f] = yy; return 1;
    }
    if(yy==-1){
        st.push({{-1, xx}, {0, 1}});
        ans -= 1ll*nodes[xx].f.size()*nodes[xx].s.size();
        nodes[xx].s.push_back(p.s);
        ans += 1ll*nodes[xx].f.size()*nodes[xx].s.size();
        yid[p.s] = xx; return 1;
    } if(xx==yy) return 0;
    if(nodes[xx].f.size()+nodes[xx].s.size()>nodes[yy].f.size()+nodes[yy].s.size()) swap(xx, yy);
    st.push({{xx, yy}, {nodes[xx].f.size(), nodes[xx].s.size()}});
    ans -= 1ll*nodes[xx].f.size()*nodes[xx].s.size();
    ans -= 1ll*nodes[yy].f.size()*nodes[yy].s.size();
    reverse(nodes[xx].f.begin(), nodes[xx].f.end());
    reverse(nodes[xx].s.begin(), nodes[xx].s.end());
    for(auto x : nodes[xx].f) nodes[yy].f.push_back(x), xid[x] = yy;
    for(auto y : nodes[xx].s) nodes[yy].s.push_back(y), yid[y] = yy;
    nodes[xx].f.clear(); nodes[xx].s.clear();
    ans += 1ll*nodes[yy].f.size()*nodes[yy].s.size(); return 1;
}

void roll_back(){
    if(st.empty()) return;
    int u = st.top().f.f, v = st.top().f.s;
    int xsiz = st.top().s.f, ysiz = st.top().s.s; st.pop();
    ans -= 1ll*nodes[v].f.size()*nodes[v].s.size();
    for(int i = 0; i<xsiz; ++i){
        xid[nodes[v].f.back()] = u;
        if(u!=-1) nodes[u].f.push_back(nodes[v].f.back());
        nodes[v].f.pop_back();
    }
    for(int i = 0; i<ysiz; ++i){
        yid[nodes[v].s.back()] = u;
        if(u!=-1) nodes[u].s.push_back(nodes[v].s.back());
        nodes[v].s.pop_back();
    }
    ans += 1ll*nodes[v].f.size()*nodes[v].s.size();
    if(u!=-1) ans += 1ll*nodes[u].f.size()*nodes[u].s.size();
}

void add(pii p, int l, int r, int v, int tl, int tr){
    if(tr<l || tl>r) return;
    if(l<=tl && tr<=r){
        tree[v].push_back(p);
        return;
    }
    int tm = (tl+tr)>>1;
    add(p, l, r, v<<1, tl, tm);
    add(p, l, r, v<<1|1, tm+1, tr);
}

void dfs(int v, int tl, int tr){
    int cnt = 0;
    for(auto p : tree[v])
        cnt += unite(p);
    if(tl==tr) cout << ans << ' ';
    else{
        int tm = (tl+tr)>>1;
        dfs(v<<1, tl, tm);
        dfs(v<<1|1, tm+1, tr);
    }
    for(int i = 0; i<cnt; ++i)
        roll_back();
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    memset(xid, -1, sizeof xid);
    memset(yid, -1, sizeof yid);
    cin >> q;
    for(int i = 0; i<q; ++i){
        int x, y; cin >> x >> y;
        if(lst.count({x, y}))
            add({x, y}, lst[{x, y}], i-1, 1, 0, q-1), lst.erase({x, y});
        else lst[{x, y}] = i;
    }
    for(auto [p, t] : lst)
        add(p, t, q-1, 1, 0, q-1);
    dfs(1, 0, q-1);
}