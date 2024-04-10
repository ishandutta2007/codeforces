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
using T = long long;
using pii = pair<ll, ll>;
const int MM = 1e6+5;

int n, m, p;
ll stx[MM];
ll ans = LLONG_MIN/5;

struct st{
    ll op, x, l, val;
//    st(int _op, int _x, int _l, ll _val){
//        op = _op, x = _x, l = _l, val = _val;
//    }
    bool operator<(const st &o) const{
        if(x == o.x)
            return op < o.op;
        return x < o.x;
    }
};
vector<st> v;
pii in[MM];

struct node{
    T val, lp;
    void apply(T vv){
        val += vv;
        lp += vv;
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = LLONG_MIN/5;
    //default value
    T merge(T va, T vb){
        return max(va, vb);
    }
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        T &val = tree[rt].lp;
        if(nl != nr){
            tree[lc].apply(val);
            tree[rc].apply(val);
        }
        val = 0;
    }
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            tree[rt].val = -stx[l]; //INIT
            tree[rt].lp = 0;
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
            tree[rt].apply(val);
            return;
        }
        push_down(rt, nl, nr);
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        push_down(rt, nl, nr);
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
} t;

int main(){
    memset(stx, 0x3f, sizeof stx);
    scanf("%d %d %d", &n, &m, &p);
    //scan(n, m, p);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &in[i].first, &in[i].second);
        assert(in[i].first <= 1e6);
        //scan(in[i].first, in[i].second);
    }
    sort(in, in+n);
    for(int i = n-2; i >= 0; i--)
        in[i].second = min(in[i].second, in[i+1].second);
    for(int i = n-1; i >= 0; i--){
        stx[in[i].first] = min(stx[in[i].first], in[i].second);
    }
    for(int i = MM-2; i >= 0; i--){
        if(stx[i] > 1e9){
            stx[i] = stx[i+1];
        }
    }
    t.build();
    
    for(int i = 0; i < m; i++){
        scanf("%lld %lld", &in[i].first, &in[i].second);
        assert(in[i].first <= 1e6);
        //scan(in[i].first, in[i].second);
    }
    sort(in, in+m);
    for(int i = m-2; i >= 0; i--)
        in[i].second = min(in[i].second, in[i+1].second);
    for(int i = 1; i < m; i++){ //same defence val?
        if(in[i].first == in[i-1].first){
            in[i].second = min(in[i].second, in[i-1].second);
        }
    }
    for(int i = m-1; i > 0; i--){
        in[i].second -= in[i-1].second;
    }
    for(int i = 0; i < m; i++){
        v.push_back({0, in[i].first, 0, -in[i].second});
        //printf("add "); print(in[i].first, -in[i].second);
    }
    /*
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        v.push_back({0, b, 1, -a});
        //at b, now need [1, MM) all -= a
    }
     */
    for(int i = 0,a,b,c; i < p; i++){
        //scan(a, b, c);
        scanf("%d %d %d", &a, &b, &c);
        assert(a <= 1e6);
        assert(b <= 1e6);
        v.push_back({1, b, a+1, c});
        //at b, now (a, MM) += c
        //strictly greater
    }
    stable_sort(v.begin(), v.end());
    for(auto i: v){
        t.update(i.l, MM-1, i.val);
        //print(i.op, i.l, i.val);
        if(i.op == 0){
            //only update after gets covered
            ans = max(ans, t.tree[1].val);
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
/*
3 4 4
2 3
4 7
5 2
2 4
3 2
4 5
5 11
3 3 3
1 2 4
2 1 6
3 4 6

 */