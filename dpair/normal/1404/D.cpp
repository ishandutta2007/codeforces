//
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
const double pi = 3.141592653589793238462643383279;
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) {return x < y ? x : y;}
template <typename T>
inline T mx(const T x, const T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, const T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, const T y) {(x < y) && (x = y);}
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) {return mx(x, mx(args...));}
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) {return mn(x, mn(args...));}
}
using namespace MyMinMax;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */
int n;
const int MAXN = 1e6 + 5;
int col[MAXN];
int s[2][MAXN], t[2], S[2];
int v[MAXN];

int head[MAXN], e[MAXN << 2], cnt, nxt[MAXN << 2];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
inline void link(int u, int v){add(u, v);add(v, u);}

void dfs(int x){
    const int c = col[x];
    S[c] += x;s[c][++ t[c]] = x;
    for (int i = head[x];i;i = nxt[i]){
        if(~col[e[i]]) continue;
        col[e[i]] = c ^ 1;dfs(e[i]);
    }
}

signed main(){
    scanf("%d", &n);
    if(n & 1){
        memset(col, -1, sizeof(col));
        printf("Second\n");
        fflush(stdout);
        rep(i, 1, n << 1){
            int x;scanf("%d", &x);
            if(v[x]) link(v[x], i);
            else v[x] = i;
        }
        rep(i, 1, n) link(i, i + n);
        rep(i, 1, (n << 1)) if(!~col[i]) {col[i] = 1; dfs(i); }
        if(S[0] & 1) {
            rep(i, 1, n) printf("%d ", s[1][i]);
            printf("\n");fflush(stdout);
        }
        else{
            rep(i, 1, n) printf("%d ", s[0][i]);
            printf("\n");fflush(stdout);
        }
    }
    else{
        printf("First\n");
        rep(i, 1, n << 1) printf("%d ", (i - 1) % n + 1);
        printf("\n");fflush(stdout);
    }
    int num;
    scanf("%d", &num);
}