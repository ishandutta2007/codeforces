#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, k, sz[MM], dep[MM];
vector<int> v, adj[MM];

int dfs(int cur, int pre){
    sz[cur] = 1;
    dep[cur] = dep[pre]+1;
    for(int u: adj[cur]){
        if(u != pre)
            sz[cur] += dfs(u, cur);
    }
    v.emplace_back(dep[cur]-1 - (sz[cur]-1));
    return sz[cur];
}

int main(){
    scan(n, k);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    dfs(1, 0);
    
    sort(all(v));
    reverse(all(v));
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ans += v[i];
    }
    print(ans);
    
    return 0;
}