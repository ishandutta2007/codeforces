#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
const int CN = 2e5 + 10;
int read(){
    int s = 0, ne = 1; char c = getchar();
    for(;c < '0' || c > '9';c = getchar()) if(c == '-') ne = -1;
    for(;c >= '0' && c <= '9';c = getchar()) s = (s << 1) + (s << 3) + c - '0';
    return s * ne;
}
int Test, n, m, K, X[CN], Y[CN], W[CN], id[CN], fa[CN]; vector<int> G[CN];
bool cmp(int i, int j) {return (W[i] <= K && W[j] <= K) ? W[i] > W[j] : W[i] < W[j];}
int fd(int x) {return fa[x] ^ x ? fa[x] = fd(fa[x]) : x;}
LL work(){
    int tot = n, mx = 0, x, y; int p = 1;
    for(; p <= m; p++){
        int i = id[p], u = X[i], v = Y[i], w = W[i];
        if(w > K) break;
        u = fd(u), v = fd(v); if(u == v) continue;
        G[u].pb(v), G[v].pb(u), fa[u] = v, tot--;
        if(!mx) {mx = w, x = u, y = v;}
    }
    if(tot > 1){
        LL ans = 0;
        for(; p <= m; p++){
            int i = id[p], u = X[i], v = Y[i], w = W[i];
            u = fd(u), v = fd(v); if(u == v) continue;
            fa[u] = v, tot--, ans += w - K;
        }
        return ans;
    }
    for(; p <= m; p++){
        int i = id[p], u = X[i], v = Y[i], w = W[i];
        if(K - mx > w - K) return 0ll + w - K;
    }
    return 0ll + K - mx;
}
int main()
{
//    freopen("_in.in", "r", stdin);
    Test = read(); while(Test--){
        n = read(), m = read(), K = read();
        for(int i = 1; i <= n; i++) fa[i] = i, G[i].clear();
        for(int i = 1; i <= m; i++) X[i] = read(), Y[i] = read(), W[i] = read(), id[i] = i;
        sort(id + 1, id + m + 1, cmp);
        printf("%lld\n", work());    
    }
    return 0;
}