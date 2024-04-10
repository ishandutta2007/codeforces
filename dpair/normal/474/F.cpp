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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

LL gcd(LL x, LL y){return !y ? x : gcd(y, x % y);}
inline LL lcm(LL x, LL y){return x / gcd(x, y) * y;}
typedef pair <LL, int> pi;
int n;
LL a[100005];
struct SegTree{
    pi num[400005];
    LL sig[400005];
    inline void pushup(int rt){
        sig[rt] = gcd(sig[rt << 1], sig[rt << 1 | 1]);
        if(num[rt << 1].first == num[rt << 1 | 1].first) num[rt] = make_pair(num[rt << 1].first, num[rt << 1].second + num[rt << 1 | 1].second);
        else{
            if(num[rt << 1].first < num[rt << 1 | 1].first) num[rt] = num[rt << 1];
            else num[rt] = num[rt << 1 | 1];
        }
    }
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    void build(int rt, int l, int r){
        if(l == r){
            num[rt] = make_pair(a[l], 1);
            sig[rt] = a[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
    }
    pi query_mn(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return num[rt];
        int mid = (l + r) >> 1;
        if(x <= mid && y > mid){
            pi q1 = query_mn(LSON, x, y), q2 = query_mn(RSON, x, y);
            if(q1.first == q2.first) return make_pair(q1.first, q1.second + q2.second);
            else {
                if(q1.first < q2.first) return q1;
                else return q2;
            }
        }
        if(x <= mid) return query_mn(LSON, x, y);
        if(y > mid) return query_mn(RSON, x, y);
        return make_pair(0ll, 0);
    }
    LL query_sig(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return sig[rt];
        int mid = (l + r) >> 1;LL ret = 0;
        if(x <= mid) ret = gcd(ret, query_sig(LSON, x, y));
        if(y > mid) ret = gcd(ret, query_sig(RSON, x, y));
        return ret;
    }
}t;

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    t.build(1, 1, n);
    int Q;read(Q);
    while(Q --){
        int l, r;read(l);read(r);
        LL bruh = t.query_sig(1, 1, n, l, r);
        pi dude = t.query_mn(1, 1, n, l, r);
        if(bruh ^ dude.first) fprint(r - l + 1, 10);
        else fprint(r - l + 1 - dude.second, 10);
    }
}