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

inline LL gcd(LL x, LL y){return !y? x : gcd(y, x % y);}

int n, m;
LL c[500005];
vector <int> vec[500005];
map <LL, LL> res;

const LL MOD = 998244353;

inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = (ret * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return ret;
}

inline LL gethash(int x){
    LL ret = 0;
    while(!vec[x].empty()){
        ret = (ret + ksm(131ll, vec[x].back())) % MOD;
        vec[x].pop_back();
    }
    return ret;
}

inline void work(){
    read(n);read(m);
    res.erase(res.begin(), res.end());
    for (register int i = 1;i <= n;i ++) read(c[i]);
    while(m --){
        int u, v;read(u);read(v);
        vec[v].push_back(u);
    }
    LL ans = 0;
    for (register int i = 1;i <= n;i ++) {if(vec[i].empty()) continue;res[gethash(i)] += c[i];}
    for (auto it = res.begin();it != res.end();++ it) ans = gcd(ans, it -> second);
    fprint(ans, 10);
}

int main(){
    int ___;
    read(___);
    while(___ --) work();
}