#include <cstdio>
#include <cstring>
#include <queue>
using std :: queue;

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
template <typename T, typename ...Args>
inline void read(T &x, Args &...args){
    read(x);read(args...);
}
typedef __int128_t LL;
int n;
#define MAXN 200005
LL a[MAXN], b[MAXN];
int fa[MAXN];
int d[MAXN];
queue <int> q;
inline bool check(LL x){
    for (int i = 1;i <= n;++ i) d[i] = 0;
    for (int i = 1;i <= n;++ i){
        b[i] = a[i];
        d[fa[i]] ++;
    }
    while(!q.empty()) q.pop();
    for (int i = 1;i <= n;++ i){
        if(!d[i]) q.push(i), b[i] -= x;
    }
    while(!q.empty()){
        int x = q.front();q.pop();
        if(b[x] > 0) return false;
        if(fa[x] == 0) continue;
        b[fa[x]] += b[x];
        if(!(-- d[fa[x]])) q.push(fa[x]);
    }
    return 1;
}

int main(){
    read(n);
    LL l = 0, r = 0, ans = 0;
    for (int i = 2;i <= n;++ i) read(fa[i]);
    for (int i = 1;i <= n;++ i) read(a[i]), r += a[i];
    ans = r + 1;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    fprint(ans, 10);
}