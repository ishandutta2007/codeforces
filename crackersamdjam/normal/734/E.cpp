#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+1;

int N, v[MM], id[MM];
vector<int> adj[MM], adjr[MM];

void dfs(int cur, int pre, int p){
    if(v[cur] ^ v[p])
        p = cur;
    id[cur] = p;
    for(int u: adj[cur])
        if(u ^ pre)
            dfs(u, cur, p);
}

int l = -1, t;
void dfsr(int cur, int pre, int dis){
    if(dis > l)
        l = dis, t = cur;
    for(int u: adjr[cur]){
        if(u ^ pre)
            dfsr(u, cur, dis+1);
    }
}

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++)
        scan(v[i]);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++){
        if(adj[i].size() == 1){
            dfs(i, 0, i);
            break;
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int u: adj[i]){
            if(id[i] ^ id[u])
                adjr[id[i]].push_back(id[u]);
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(adjr[i].size()){
            dfsr(i, 0, 0);
            break;
        }
    }
    
    dfsr(t, 0, 0);
    
    print((l+1)/2);
    
    return 0;
}