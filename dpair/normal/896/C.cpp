#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
struct NODE{
    int l, r;
    mutable LL val;
    NODE (int tmp1, int tmp2 = -1, LL tmp3 = 0) : l(tmp1), r(tmp2), val(tmp3){}
    inline bool operator < (const NODE &tmp) const{return l < tmp.l;}
};
set <NODE> ODT;
inline LL ksm(LL x, LL y, LL MOD){
    LL ret = 1;
    while(y){
        if(y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
typedef set<NODE> :: iterator IT;
inline IT split(int x){
    IT it = ODT.lower_bound(NODE(x));
    if(it != ODT.end() && it -> l == x) return it;
    -- it;
    int L = it -> l, R = it -> r;
    LL Val = it -> val;
    ODT.erase(it);
    ODT.insert(NODE(L, x - 1, Val));
    return ODT.insert(NODE(x, R, Val)).first;
}
inline void add(int l, int r, LL z){
    IT R = split(r + 1), L = split(l);
    while(L != R){
        L -> val += z;
        ++ L;
    }
}
inline void assign(int l, int r, LL val){
    IT R = split(r + 1), L = split(l);
    ODT.erase(L, R);
    ODT.insert(NODE(l, r, val));
}
inline LL query(int l, int r, int k, LL MOD){
    IT R = split(r + 1), L = split(l);
    LL ret = 0;
    while(L != R){
        ret = (ret + 1ll * (L -> r - L -> l + 1) * ksm(L -> val % MOD, k, MOD)) % MOD;
        ++ L;
    }
    return ret;
}
vector <pair<LL, int> > vec;
inline LL Kth(int l, int r, int k){
    vec.clear();
    IT R = split(r + 1), L = split(l);
    while(L != R){
        vec.push_back(make_pair(L -> val, L -> r - L -> l + 1));
        ++ L;
    }
    sort(vec.begin(), vec.end());
    for (register int i = 0;i < vec.size();i ++){
        k -= vec[i].second;
        if(k <= 0) return vec[i].first;
    }
}
LL vmax, seed;
inline LL rnd(){
    LL ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}
#define MAXN 100005
LL a[MAXN];
int n, m;
int main(){
    read(n);read(m);read(seed);read(vmax);
    for (register int i = 1;i <= n;i ++) a[i] = rnd() % vmax + 1, ODT.insert(NODE(i, i, a[i]));
    ODT.insert(NODE(n + 1, n + 1, 0));
    for (register int i = 1;i <= m;i ++){
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        int x, y;
        if(l > r) swap(l, r);
        if(op == 3) x = rnd() % (r - l + 1) + 1;
        else x = rnd() % vmax + 1;
        if(op == 4) y = rnd() % vmax + 1;
        if(op == 1) add(l, r, x);
        if(op == 2) assign(l, r, x);
        if(op == 3) fprint(Kth(l, r, x), 10);
        if(op == 4) fprint(query(l, r, x, y), 10);
    }
}