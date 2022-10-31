#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1<<19;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll seg_mx[N<<1], lazy[N<<1];

void push(int v, int tl, int tr){
    seg_mx[v] += lazy[v];
    if(tl!=tr)
        lazy[v<<1] += lazy[v],
        lazy[v<<1|1] += lazy[v];
    lazy[v] = 0;
}

void upd_mx(int l, int r, ll val, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr<l || tl>r) return;
    if(l<=tl && tr<=r){
        lazy[v] += val;
        push(v, tl, tr);
        return;
    }
    int tm = (tl+tr)>>1;
    upd_mx(l, r, val, v<<1, tl, tm);
    upd_mx(l, r, val, v<<1|1, tm+1, tr);
    seg_mx[v] = max(seg_mx[v<<1], seg_mx[v<<1|1]);
}

ll query_mx(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr<l || tl>r) return -INF;
    if(l<=tl && tr<=r) return seg_mx[v];
    int tm = (tl+tr)>>1;
    return max(query_mx(l, r, v<<1, tl, tm), query_mx(l, r, v<<1|1, tm+1, tr));
}

ll seg_mn[N<<1];

void upd_mn(int pos, ll val, int v = 1, int tl = 0, int tr = N-1){
    if(tr<pos || tl>pos) return;
    if(tl==tr){
        seg_mn[v] = val;
        return;
    }
    int tm = (tl+tr)>>1;
    upd_mn(pos, val, v<<1, tl, tm);
    upd_mn(pos, val, v<<1|1, tm+1, tr);
    seg_mn[v] = min(seg_mn[v<<1], seg_mn[v<<1|1]);
}

ll query_mn(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    if(tr<l || tl>r) return INF;
    if(l<=tl && tr<=r) return seg_mn[v];
    int tm = (tl+tr)>>1;
    return min(query_mn(l, r, v<<1, tl, tm), query_mn(l, r, v<<1|1, tm+1, tr));
}

int find_smol(ll val, int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr)
        return seg_mn[v]<val?tl:N;
    int tm = (tl+tr)>>1;
    if(seg_mn[v<<1]<val)
        return find_smol(val, v<<1, tl, tm);
    return find_smol(val, v<<1|1, tm+1, tr);
}

int n, q, arr[3][N];
vector<pair<int, int>> qs[N];
multiset<int> wtf[N];
ll pre[N], que[N], dp[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i<=n; ++i)
        cin >> arr[0][i], que[i] = arr[0][i];
    for(int i = 1; i<=n; ++i)
        cin >> arr[1][i], pre[i] = arr[1][i];
    for(int i = 1; i<=n; ++i)
        cin >> arr[2][i];
    for(int i = 1; i<=n; ++i)
        pre[i] += pre[i-1], que[i] += que[i-1];
    for(int i = 1; i<=q; ++i){
        int l, r, k; cin >> l >> r >> k;
        qs[r].push_back({l, k});
        wtf[l].insert(k);
    }
    fill(seg_mn, seg_mn+(N<<1), INF);
    for(int i = 1; i<=n; ++i)
        if(!wtf[i].empty())
            upd_mn(i, (*wtf[i].begin()));
    ll tmp = INF;
    for(int i = 1; i<=n; ++i){
        if(!wtf[i].empty())
            tmp = min(tmp, (ll)(*wtf[i].begin()));
        upd_mx(i-1, i-1, -tmp);
    }
    upd_mx(0, 0, que[1]-pre[0]);
    int ops = 0;
    for(int i = 1; i<=n; ++i){
        for(auto [l, k] : qs[i-1]){
            ll og = query_mn(1, l);
            int rbd = find_smol(og);
            wtf[l].erase(wtf[l].find(k));
            ll val = wtf[l].empty()?INF:(*wtf[l].begin());
            upd_mn(l, val);
            val = query_mn(1, l);
            if(val==og) continue;
            int cur = l, nxt = find_smol(val);
            while(cur<rbd){ ++ops;
                upd_mx(cur-1, nxt-1-1, og-val);
                if(nxt==N) break;
                cur = nxt; 
                val = seg_mn[cur+N];
                nxt = find_smol(val);
            }
        }
        dp[i] = query_mx(0, i-1)+pre[i];
        upd_mx(i, i, max(que[i+1]-pre[i], dp[i]-pre[i]));
    }
    ll ans = -INF, suf = 0;
    for(int i = n; i>=1; --i)
        suf += arr[2][i], ans = max(ans, dp[i]+suf);
    cout << ans << '\n';
}