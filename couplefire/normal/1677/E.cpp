#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = 1<<18;
 
struct seg{
    ll sum[N<<1],lazy[N<<1];
    seg(){}
    void push(int v, int tl, int tr){
        sum[v] += 1ll*(tr-tl+1)*lazy[v];
        if(tl!=tr)
            lazy[v<<1] += lazy[v],
            lazy[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
    void upd(int l, int r, int inc, int v = 1, int tl = 0, int tr = N-1){
        push(v, tl, tr);
        if(tr<l || tl>r) return;
        if(l<=tl && tr<=r){
            lazy[v] += inc;
            push(v, tl, tr);
            return;
        }
        int tm = (tl+tr)>>1;
        upd(l, r, inc, v<<1, tl, tm);
        upd(l, r, inc, v<<1|1, tm+1, tr);
        sum[v] = sum[v<<1]+sum[v<<1|1];
    }
    ll query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
        push(v, tl, tr);
        if(tr<l || tl>r) 
            return 0ll;
        if(l<=tl && tr<=r)
            return sum[v];
        int tm = (tl+tr)>>1;
        return query(l, r, v<<1, tl, tm)+query(l, r, v<<1|1, tm+1, tr);
    }
} seg_x, seg_y;
 
int n, q;
int per[N], pos[N];
int nxt[N], prv[N];
array<vector<pair<int, int>>, N> queries_x, queries_y;
array<vector<pair<int, int>>, N> events_x, events_y;
array<vector<int>, N> fs;
ll ans[N<<2];
 
int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i<=n; ++i)
        cin >> per[i], pos[per[i]] = i;
    for(int i = 0; i<q; ++i){
        int l, r; cin >> l >> r;
        queries_y[r].push_back({n+1-l, i});
        queries_x[n+1-l].push_back({r, i});
    }
    for(int i = 1; i<=n; ++i)
        for(int j = i; j<=n; j+=i)
            fs[j].push_back(i);
    per[0] = per[n+1] = N;
    {
        stack<int> st; st.push(0);
        for(int i = 1; i<=n; ++i){
            while(per[st.top()]<per[i])
                st.pop();
            prv[i] = st.top();
            st.push(i);
        }
    }
    {
        stack<int> st; st.push(n+1);
        for(int i = n; i>=1; --i){
            while(per[st.top()]<per[i])
                st.pop();
            nxt[i] = st.top();
            st.push(i);
        }
    }
    for(int i = 1; i<=n; ++i){
        int l = prv[i], r = nxt[i];
        if(i-l<r-i){
            int cur = N;
            for(auto x : fs[per[i]])
                if(pos[x]>=i && pos[per[i]/x]>=i && per[i]/x!=x)
                    cur = min(cur, max(pos[x], pos[per[i]/x]));
            for(int j = i; j>=l+1; --j){
                if(per[i]%per[j]==0 && pos[per[i]/per[j]]>j)
                    cur = min(cur, pos[per[i]/per[j]]);
                cur = max(cur, i);
                if(cur<r) events_x[n+1-j].push_back({cur, r-1});
            }
        } else{
            int cur = -N;
            for(auto x : fs[per[i]])
                if(pos[x]<=i && pos[per[i]/x]<=i && per[i]/x!=x)
                    cur = max(cur, min(pos[x], pos[per[i]/x]));
            for(int j = i; j<=r-1; ++j){
                if(per[i]%per[j]==0 && pos[per[i]/per[j]]<j)
                    cur = max(cur, pos[per[i]/per[j]]);
                cur = min(cur, i);
                if(cur>l) events_y[j].push_back({n+1-cur, n+1-l-1});
            }
        }
    }
    for(int x = 1; x<=n; ++x){
        for(auto [y1, y2] : events_x[x])
            seg_x.upd(y1, y2, 1);
        for(auto [y, id] : queries_x[x])
            ans[id] += seg_x.query(0, y);
    }
    for(int y = 1; y<=n; ++y){
        for(auto [x1, x2] : events_y[y])
            seg_y.upd(x1, x2, 1);
        for(auto [x, id] : queries_y[y])
            ans[id] += seg_y.query(0, x);
    }
    for(int i = 0; i<q; ++i)
        cout << ans[i] << '\n';
}