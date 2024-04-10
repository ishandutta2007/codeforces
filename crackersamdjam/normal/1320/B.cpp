#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

int n, m, k, p[MM], ord[MM], dp[MM], dis[MM];
vector<int> adj[MM], adjr[MM];
queue<int> q;
int a1, a2;

int main(){
    scan(n, m);
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adjr[b].emplace_back(a);
    }
    scan(k);
    memset(ord, 0x3f, sizeof ord);
    for(int i = 0; i < k; i++){
        scan(p[i]);
        ord[p[i]] = i;
    }
    memset(dis, 0x3f, sizeof dis);
    q.push(p[k-1]);
    dis[p[k-1]] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int u: adjr[cur]){
            if(dis[cur]+1 < dis[u]){
                dis[u] = dis[cur]+1;
                q.push(u);
            }
        }
    }
    
    for(int i = 0; i < k-1; i++){
        int cur = p[i], d = 1e9, nx = dis[p[i+1]], cnt = 0;
        for(int u: adj[cur]){
            if(dis[u] < d){
                d = dis[u];
                cnt = 1;
            }
            else if(dis[u] == d)
                cnt++;
        }
        //print(cur, nx, d, cnt);
        if(nx > d){
            a1++, a2++;
        }
        else if(nx == d and cnt > 1){
            a2++;
        }
    }
    print(a1, a2);
    
    return 0;
}