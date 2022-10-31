#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 400005;

struct node{
    ll num = 0, sum = 0, prod = 0;
} tree[N<<2];
ll n, q, og[N>>1], qs[N>>1], cur_sum = 0;
vector<ll> stuff;
map<ll, int> mp;

node comb(node a, node b){
    node res;
    res.num = a.num+b.num;
    res.sum = a.sum+b.sum;
    res.prod = a.prod+b.prod+b.sum*a.num;
    return res;
}

void add(int pos, int v = 1, int tl = 0, int tr = N-1){
    if(tr<pos || tl>pos) return;
    if(tl==tr){
        if(tree[v].num) cur_sum -= tree[v].sum, tree[v] = {0, 0, 0}, --n;
        else tree[v] = {1, stuff[tl], stuff[tl]}, cur_sum += stuff[tl], ++n;
        return;
    }
    int tm = (tl+tr)>>1;
    add(pos, v<<1, tl, tm); add(pos, v<<1|1, tm+1, tr);
    tree[v] = comb(tree[v<<1], tree[v<<1|1]);
}

int find(int cnt, int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr) return tl;
    int tm = (tl+tr)>>1;
    if(tree[v<<1].num>=cnt) return find(cnt, v<<1, tl, tm);
    return find(cnt-tree[v<<1].num, v<<1|1, tm+1, tr);
}

node query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    if(tr<l || tl>r) return {0, 0, 0};
    if(l<=tl && tr<=r) return tree[v];
    int tm = (tl+tr)>>1;
    return comb(query(l, r, v<<1, tl, tm), query(l, r, v<<1|1, tm+1, tr));
}

ll get(){
    int lo = 0, hi = (n-1)/2;
    while(lo<hi){
        int mid = lo+(hi-lo+1)/2;
        node f1 = query(0, find(mid+1));
        node f2 = query(find(n-mid+1), N-1);
        if(f1.sum-f2.sum>0) lo = mid;
        else hi = mid-1;
    }
    node f1 = query(0, find(lo+1));
    node f2 = query(find(n-lo+1), N-1);
    return cur_sum-2*(f1.sum*(lo+2)-f1.prod-f2.prod)+(lo==(n-1)/2&&n%2?f1.sum-f2.sum:0);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 0; i<n; ++i)
        cin >> og[i], stuff.push_back(og[i]);
    for(int i = 0; i<q; ++i){
        ll t, x; cin >> t >> x;
        stuff.push_back(x); qs[i] = x;
    }
    sort(stuff.begin(), stuff.end());
    stuff.erase(unique(stuff.begin(), stuff.end()), stuff.end());
    for(int i = 0; i<(int)stuff.size(); ++i)
        mp[stuff[i]] = i;
    for(int i = 0, end = n; i<end; ++i)
        add(mp[og[i]]);
    n /= 2;
    cout << get() << '\n';
    for(int i = 0; i<q; ++i){
        add(mp[qs[i]]);
        cout << get() << '\n';
        // if(i==0) cerr << cur_sum << '\n';
    }
}