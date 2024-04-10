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
const int MM = 2e5+5;

int n, m, par[MM], f[MM], s[MM], ptr;
vector<int> adj[MM];

void dfs(int cur, int pre){
    par[cur] = pre;
    f[cur] = ++ptr;
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur);
    }
    s[cur] = ++ptr;
}

int main(){
    scan(n, m);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    dfs(1, 0);
    par[1] = 1;
    
    for(int t = 0,k,a,b; t < m; t++){
        vector<pair<int, int>> v;
        scan(k);
        while(k--){
            scan(a);
            a = par[a];
            v.emplace_back(f[a], s[a]);
        }
        sort(all(v));
        int mx = 1e9, ans = 1;
        for(auto i: v){
            if(i.second > mx)
                ans = 0;
            mx = i.second;
        }
        puts(ans ? "YES" : "NO");
    }
    
    return 0;
}