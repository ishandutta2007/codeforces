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
using pii = pair<int, int>;
const int MM = 2e5+5;

int t, n, m, A, B, C, dist[3][MM];
ll p[MM];
vector<int> adj[MM];
queue<int> q;

void go(int *dis, int rt){
    dis[rt] = 0;
    q.push(rt);
    while(q.size()){
        int cur = q.front(); q.pop();
        for(int u: adj[cur]){
            if(dis[cur] + 1 < dis[u]){
                dis[u] = dis[cur] + 1;
                q.push(u);
            }
        }
    }
}

int main(){
    scan(t);
    while(t--){
        scan(n, m, A, B, C);
        for(int i = 1; i <= m; i++)
            scan(p[i]);
        sort(p+1, p+m+1);
        for(int i = 1; i <= m; i++)
            p[i] += p[i-1];
        
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            dist[0][i] = dist[1][i] = dist[2][i] = 0x3f3f3f3f;
        }
        for(int i = 0,a,b; i < m; i++){
            scan(a, b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        go(dist[0], A);
        go(dist[1], B);
        go(dist[2], C);
        
        ll ans = LLONG_MAX;
        for(int i = 1; i <= n; i++){
            int tot = dist[0][i]+dist[1][i]+dist[2][i], tw = dist[1][i];
            ll v = ((tot <= m ? p[tot] : 1e16) + p[tw]);
//            print(i, dist[0][i], dist[1][i], dist[2][i], tot, tw, v);
            ans = min(ans, v);
        }
        
        print(ans);
    }
    
    
    return 0;
}