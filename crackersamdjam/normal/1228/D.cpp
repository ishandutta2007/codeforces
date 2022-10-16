#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+2;

int n, m, id[MM], sz[3];
set<int> adj[MM];

int main(){
    
    scan(n, m);
    
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    int nx = 0;
    for(int i = 1; i <= n; i++){
        if(adj[1].count(i))
            nx = i;
        else
            id[i] = 1, sz[1]++;
    }
    
    if(!nx)
        return 0*puts("-1");
    
    
    for(int i = 2; i <= n; i++){
        if(adj[nx].count(i) || id[i])
            continue;
        id[i] = 2, sz[2]++;
    }
    
    if(!(sz[0] = n-sz[1]-sz[2]))
        return 0*puts("-1");
    
    for(int i = 1; i <= n; i++){
        for(int u: adj[i]){
            if(id[u] == id[i])
                return 0*puts("-1");
        }
        if(adj[i].size() != n-sz[id[i]])
            return 0*puts("-1");
    }
    
    for(int i = 1; i <= n; i++)
        printf("%d%c", id[i]+1, " \n"[i==n]);
    
    return 0;
}