#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

const int N = 1<<20;

int n, q; set<pii> se;
ll seg[N<<1], lazy[N<<1];
ll sofar[N];

void push(int v, int tl, int tr){
    seg[v] += lazy[v];
    if(tl!=tr)
        lazy[v<<1] += lazy[v],
        lazy[v<<1|1] += lazy[v];
    lazy[v] = 0;
}

void upd(int l, int r, ll val, int v = 1, int tl = 0, int tr = N-1){
    if(tr<l || tl>r) return;
    if(l<=tl && tr<=r)
        return lazy[v] += val, void();
    push(v, tl, tr);
    int tm = (tl+tr)>>1;
    upd(l, r, val, v<<1, tl, tm);
    upd(l, r, val, v<<1|1, tm+1, tr);
    seg[v] = seg[v<<1]+seg[v<<1|1];
}

ll get(int pos, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tl==tr) return seg[v];
    int tm = (tl+tr)>>1;
    if(pos<=tm) return get(pos, v<<1, tl, tm);
    return get(pos, v<<1|1, tm+1, tr);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    se.insert(pii{-1, 0});
    se.insert(pii{n-1, 0});    
    while(q--){
        string s; cin >> s;
        if(s[0]=='C'){
            int l, r, c; cin >> l >> r >> c;
            --l; --r; --c;
            auto it = se.lower_bound(pii{l, -1});
            if(prev(it)->f<l-1)
                it = next(se.insert({l-1, it->s}).f);
            int prv = l-1;
            while(it!=se.end() && it->f<=r){
                upd(prv+1, it->f, -sofar[c]+sofar[it->s]);
                prv = it->f; it = se.erase(it);
            }
            if(prv!=r) upd(prv+1, r, -sofar[c]+sofar[it->s]);
            se.insert(pii{r, c});
        } else if(s[0]=='A'){
            int c, val; cin >> c >> val; --c;
            sofar[c] += val;
        } else{
            int pos; cin >> pos; --pos;
            int col = (*se.lower_bound(pii{pos, -1})).s;
            cout << get(pos)+sofar[col] << '\n';
        }
    }
}