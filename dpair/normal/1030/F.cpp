#include <bits/stdc++.h>
using namespace std;

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
typedef long long LL;
const LL MOD = 1000000007;
#define MAXN 200005
int n, m;
LL a[MAXN], w[MAXN];
LL c1[MAXN], c2[MAXN];
inline int lowbit(int x){return x & -x;}
inline LL query(LL c[], int x, bool type){LL ret = 0;for (;x;x -= lowbit(x)) ret += c[x], (type) && (ret = (ret + MOD) % MOD);return ret;}
inline void modify(LL c[], int x, LL y, bool type){for(;x <= n;x += lowbit(x)) c[x] += y, (type) && (c[x] = (c[x] + MOD) % MOD);}
int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i <= n;i ++) read(w[i]), modify(c1, i, w[i], 0), modify(c2, i, (a[i] - i) * w[i] % MOD, 1);
    while(m --){
        int l, r;read(l);read(r);
        if(l < 0){//first type
            l = -l;
            modify(c1, l, -w[l], 0);
            modify(c2, l, ((r - w[l]) * (a[l] - l) % MOD + MOD) % MOD, 1);
            w[l] = r;
            modify(c1, l, r, 0);
        }
        else{//second type
            int L = l, R = r, pos = l;
            LL ll = query(c1, l - 1, 0), rr = query(c1, r, 0);
            LL tot = rr - ll;
            tot = (tot >> 1) + 1;
            while(L <= R){
                int mid = (L + R) >> 1;
                if(query(c1, mid, 0) - ll >= tot) pos = mid, R = mid - 1;
                else L = mid + 1; 
            }
            LL res1 = query(c1, pos, 0), res2 = query(c1, pos - 1, 0);
            rr %= MOD, ll %= MOD, res1 %= MOD, res2 %= MOD;
            LL num = (a[pos] - (pos - l + 1) + MOD) % MOD;
            LL ans = num * (res2 - ll) % MOD;
            ans = ((ans + 1ll * (l - 1) * (rr - res1 - (res2 - ll))) % MOD + MOD) % MOD;
            ans = ((ans - query(c2, pos - 1, 1) + query(c2, l - 1, 1)) % MOD + MOD) % MOD;
            ans = (ans + query(c2, r, 1) - query(c2, pos, 1) + MOD) % MOD;
            ans = (ans - ((rr - res1) * num % MOD) + MOD) % MOD;
            fprint(ans, 10);
        }
    }
}