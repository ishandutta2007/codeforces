#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5, LOG = 25;

int n, q, dep[MM], lca[LOG][MM], val[LOG][MM];
vector<int> adj[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if((lca[i][u] != -1) && (dep[lca[i][u]] >= dep[v]))
            u = lca[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if((lca[i][u] != -1) && (lca[i][v] != -1) && (lca[i][u] != lca[i][v])){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}

int dist(int u, int v){
    return dep[u] + dep[v] - 2*dep[getlca(u, v)];
}

void dfs(int cur, int pre){
    dep[cur] = dep[pre]+1;
    lca[0][cur] = pre;
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur);
    }
}

int main(){
    memset(lca, -1, sizeof lca);
    scan(n);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, 0);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j <= n; j++){
            if(~lca[i-1][j]){
                lca[i][j] = lca[i-1][ lca[i-1][j] ];
                val[i][j] = max(val[i-1][j], val[i-1][ lca[i-1][j] ]);
            }
        }
    }
    scan(q);
    for(int i = 0,x,y,a,b,k; i < q; i++){
        scan(x, y, a, b, k);
        int v = dist(a, b);
        if(v <= k and v % 2 == k % 2){
            puts("YES");
            continue;
        }
        v = dist(a, x) + dist(b, y) + 1;
        if(v <= k and v % 2 == k % 2){
            puts("YES");
            continue;
        }
        v = dist(a, y) + dist(b, x) + 1;
        if(v <= k and v % 2 == k % 2){
            puts("YES");
            continue;
        }
        puts("NO");
    }
    
    return 0;
}