/*
    author: DPair
    language: C++11

    description:
    
*/
#pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
namespace MyMinMax{
    template <typename T>
    inline T mn(T x, T y) {return x < y ? x : y;}
    template <typename T>
    inline T mx(T x, T y) {return x > y ? x : y;}
    template <typename T>
    inline void chmin(T &x, T y) {(x > y) && (x = y);}
    template <typename T>
    inline void chmax(T &x, T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
#define MAXN 200005
int n, m;
char a[MAXN], b[MAXN];
int p[MAXN], s[MAXN];
inline void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    int it = 0;
    for (int i = 1;i <= n;++ i){
        if(a[i] == b[it + 1]) p[++ it] = i;
        if(it == m) break;
    }
    it = m;
    for (int i = n;i >= 1;-- i){
        if(a[i] == b[it]) s[it --] = i;
        if(!it) break;
    }
    int ans = 0;
    for (int i = 1;i < m;++ i) chmax(ans, s[i + 1] - p[i]);
    printf("%d\n", ans);
}


int main(){
    // int T;read(T);
    // while(T --)
    solve();
}