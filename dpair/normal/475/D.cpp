/*
    author: Mendeleyev
    language: C++

    description:
    I'm Mendeleyev.
*/
#include <unordered_map>
using std :: unordered_map;
#include <cstdio>

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


#define MAXN 100005
inline int gcd(int x, int y){return !y? x : gcd(y, x % y);}
int g[MAXN][21], lg[MAXN];
int n;
typedef long long LL;
inline int query(int l, int r){
    int k = lg[r - l + 1];
    return gcd(g[l][k], g[r - (1 << k) + 1][k]);
}

unordered_map <int, LL> cnt;

int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(g[i][0]);
    lg[0] = -1;
    for (int i = 1;i <= n;++ i) lg[i] = lg[i >> 1] + 1;
    for (int k = 1;k <= lg[n];++ k)
        for (int i = 1;i + (1 << k) - 1 <= n;++ i)
            g[i][k] = gcd(g[i][k - 1], g[i + (1 << (k - 1))][k - 1]);
    for (int i = 1;i <= n;++ i){
        int R = n;
        while(R >= i){
            int key = query(i, R);
            int l = i, r = R, pos = i;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(query(i, mid) == key) r = mid - 1, pos = mid;
                else l = mid + 1;
            }
            cnt[key] += R - pos + 1;
            R = pos - 1;
        }
    }
    int q;read(q);
    while(q --){
        int x;read(x);
        fprint(cnt[x], 10);
    }
}