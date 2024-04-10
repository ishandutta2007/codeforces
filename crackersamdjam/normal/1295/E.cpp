#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using T = pair<ll, int>;
const int MM = 2e5+2;

struct node{
    T val;
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = {1e16, 0};
    //default value
    
    T merge(T va, T vb){
        return min(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            tree[rt].val = DEF;
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            tree[rt].val = val;
            return;
        }
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
};

int n, a[MM], v[MM], at[MM];
ll psa[MM], bit[MM];

void update(int i, ll val){
    for(; i < MM; i += i&-i)
        bit[i] += val;
}

ll query(int i){
    ll ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

ll sum;
ll val(int i){
    if(i == n)
        return 1e16;
    return psa[i] - query(i) + (sum - query(i));
}

set<int> sl, sr;

int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        at[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        scan(v[i]);
        psa[i] = psa[i-1]+v[i];
    }
    
    ll ans = min(v[1], v[n]);
    sl.insert(1);
    sr.insert(1);
    //all <= i go on left, rest on right
    for(int i = 1; i <= n; i++){
        int id = at[i];
        update(id, v[id]);
        sum += v[id];
        
        ll vi = val(id);
        auto it = sr.upper_bound(id);
        while(it != sr.begin()){
            it--;
            if(vi <= val(*it)){
                it = sr.erase(it);
            }
            else break;
        }
        it = sr.upper_bound(id);
        if(it == sr.end() or vi < val(*it))
            sr.insert(id);
        if(it != sr.end())
            ans = min(ans, val(*it));
        
        it = sl.upper_bound(id);
        while(it != sl.end()){
            if(vi <= val(*it))
                it = sl.erase(it);
            else break;
        }
        it = sl.lower_bound(id);
        if(it == sl.begin() or vi < val(*--it)){
            sl.insert(id);
        }
        it = sl.lower_bound(id);
        if(it != sl.begin())
            ans = min(ans, val(*--it));
        
        ans = min(ans, vi);
    }
    
    print(ans);
    /*
    for(int i: sl)
        printf("%d ", i);
    pc(10);
    for(int i: sr)
        printf("%d ", i);
    */
    return 0;
}