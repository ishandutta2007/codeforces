#pragma GCC optimize(2, 3, "Ofast")
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

int n, m, block;
int a[500005];

inline int idb(int x){return (x / block);}

struct QUEST{
    int l, r;
    int id;
    inline bool operator <(const QUEST &tmp) const{
        return (idb(l) ^ idb(tmp.l)) ?(l < tmp.l) : ((idb(l) & 1)? r < tmp.r : r > tmp.r);
    }
}q[500005];

int cnt[500005], ret[500005];
bool vis[500005], inq[500005];
queue <int> ans;
inline void add(int x){
    if(cnt[x] == 1) vis[x] = 0;
    cnt[x] ++;
    if(cnt[x] == 1){
        vis[x] = 1;
        if(!inq[x]) {
            inq[x] = 1;
            ans.push(x);
        }
    }
}
inline void del(int x){
    if(cnt[x] == 1) vis[x] = 0;
    cnt[x] --;
    if(cnt[x] == 1){
        vis[x] = 1;
        if(!inq[x]) {
            inq[x] = 1;
            ans.push(x);
        }
    }
}
int main(){
    read(n);
    for (register int i = 1;i <= n;++ i) read(a[i]);
    read(m);block = n / sqrt(m * 2 / 3);
    for (register int i = 1;i <= m;++ i) {read(q[i].l);read(q[i].r);q[i].id = i;}
    sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    for (register int i = 1;i <= m;++ i){
        while(l < q[i].l) del(a[l ++]);
        while(l > q[i].l) add(a[-- l]);
        while(r < q[i].r) add(a[++ r]);
        while(r > q[i].r) del(a[r --]);
        while(!ans.empty() && !vis[ans.front()]) inq[ans.front()] = 0, ans.pop();
        if(!ans.empty()) ret[q[i].id] = ans.front();
    }
    for (register int i = 1;i <= m;++ i) fprint(ret[i], 10);
    return 0;
}