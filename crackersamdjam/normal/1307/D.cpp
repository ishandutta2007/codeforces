#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 2e5+5;

int n, m, k, dis[MM], rdis[MM];
vector<int> adj[MM], v;
int pre[MM], suf[MM];
//priority_queue<pii, vector<pii>, greater<pii>> q;
queue<int> q;
vector<pair<int, int>> vv;

int main(){
    scan(n, m, k);
    for(int i = 0,a; i < k; i++){
        scan(a);
        v.emplace_back(a);
    }
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int u: adj[cur]){
            if(dis[cur]+1 < dis[u]){
                dis[u] = dis[cur]+1;
                q.push(u);
            }
        }
    }
    memset(rdis, 0x3f, sizeof rdis);
    rdis[n] = 0;
    q.push(n);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int u: adj[cur]){
            if(rdis[cur]+1 < rdis[u]){
                rdis[u] = rdis[cur]+1;
                q.push(u);
            }
        }
    }
    for(int i: v)
        vv.emplace_back(dis[i], i);
    sort(vv.begin(), vv.end());
    for(int i = k-1; i; i--)
        suf[i] = max(suf[i+1], rdis[vv[i].second]);
    int ans = 0;
    for(int i = 0; i < k-1; i++){
        ans = max(ans, vv[i].first + suf[i+1] + 1);
    }
    
    print(min(ans, dis[n]));
    
    return 0;
}
/*
6 5 2
2 5
1 2
2 3
3 4
4 5
5 6

7 6 3
2 5 6
1 2
2 3
3 4
4 5
4 6
5 7
 */