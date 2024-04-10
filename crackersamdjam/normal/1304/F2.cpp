#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using T = long long;
using ll = long long;
const int MM = 4e4+5;

int n, m, k, dp[51][MM], psa[51][MM], a[51][MM];

struct node{
    T val, lp;
    void apply(T v){
        val += v;
        lp += v;
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = 0;
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
        val = DEF;
    }
    
    void build(int i, int l = 1, int r = m+m, int rt = 1){
        int nl = l, nr = r;
        tree[rt].lp = 0;
        if(l == r){
            tree[rt].val = dp[i][l];
            tree[rt].lp = 0;
            return;
        }
        build(i, l, nm, lc);
        build(i, nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int nl = 1, int nr = m+m, int rt = 1){
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
    
    T query(int l, int r, int nl = 1, int nr = m+m, int rt = 1){
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

int sum(int i, int j){
    return psa[i][j] - psa[i][max(0, j-k)];
}

int main(){
    scan(n, m, k);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            scan(psa[i][j]);
            a[i][j] = psa[i][j];
            psa[i][j] += psa[i][j-1];
        }
    }
    for(int j = k; j <= m; j++){
        dp[0][j] = sum(0, j) + sum(1, j);
    }
    t.build(0);
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            t.update(j, j+k-1, -a[i][j]);
            if(j < k)
                continue;
            if(j > k){
                t.update(j-k, j-1, a[i][j-k]);
            }
//            print(j, t.query(k, m));
            dp[i][j] = sum(i+1, j) + sum(i, j) + t.query(k, m);
        }
//        for(int j = 1; j <= m; j++)
//            printf("%d ", dp[i][j]);
//        pc(10);
        t.build(i);
    }
    int ans = *max_element(dp[n-1]+1, dp[n-1]+1+m);
    print(ans);
    
    
    return 0;
}