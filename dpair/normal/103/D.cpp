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

int n, m;
LL a[300005], sig[600005];
LL ans[300005];
struct QUE{
    int p, k;
    int id;
    inline bool operator < (const QUE &tmp) const{
        return k < tmp.k;
    }
}q[300005];

inline void work(int k){
    for (register int i = n;i >= 1;i --){
        sig[i] = sig[i + k] + a[i];
    }
}

inline LL getans(int p, int k){
    LL ret = 0;
    for (register int i = p;i <= n;i += k) ret += a[i];
    return ret;
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    read(m);
    for (register int i = 1;i <= m;i ++){
        read(q[i].p);read(q[i].k);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int pre = 0;
    for (register int i = 1;i <= m;i ++){
        if(q[i].k > sqrt(n)) {
            ans[q[i].id] = getans(q[i].p, q[i].k);
            continue;
        }
        if(pre ^ q[i].k){
            pre = q[i].k;
            work(pre);
        }
        ans[q[i].id] = sig[q[i].p];
    }
    for (register int i = 1;i <= m;i ++) fprint(ans[i], 10);
    return 0;
}