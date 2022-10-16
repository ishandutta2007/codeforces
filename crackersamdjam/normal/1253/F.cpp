#include <bits/stdc++.h>
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
const int MM = 1e5+2;

struct st{
    int u; ll d;
    st(int _u, ll _d): u(_u), d(_d){}
    bool operator <(const st &o) const{
        return d > o.d;
    }
};
struct st2{
    int a, b; ll c;
    st2(int _a, int _b, ll _c): a(_a), b(_b), c(_c){}
    bool operator <(const st2 &o) const{
        return c < o.c;
    }
};

vector<st2> add;
priority_queue<st> q;
vector<pii> adj[MM];
vector<pii> qu[MM];
int n, m, k, qr, par[MM];
pair<ll, int> dis[MM];
ll ans[MM*3];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    
    scan(n, m, k, qr);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    for(int i = 1; i <= n; i++)
        par[i] = i, dis[i] = {1e16, -1};
    
    for(int i = 1; i <= k; i++){
        dis[i] = {0, i};
        q.emplace(i, 0);
    }
    
    while(!q.empty()){
        int cur = q.top().u; ll d = q.top().d; q.pop();
        if(d > dis[cur].first) continue;
        
        for(auto e: adj[cur]){
            int u = e.first, w = e.second;
            if(d+w < dis[u].first){
                dis[u] = {d+w, dis[cur].second};
                q.emplace(u, d+w);
            }
        }
    }
    
    for(int cur = 1; cur <= n; cur++){
        for(auto e: adj[cur]){
            int u = e.first;
            if(dis[cur].second != dis[u].second)
                add.emplace_back(dis[cur].second, dis[u].second, dis[cur].first + e.second + dis[u].first);
        }
    }
    
    for(int i = 0,a,b; i < qr; i++){
        scan(a, b);
        qu[a].emplace_back(b, i);
        qu[b].emplace_back(a, i);
    }
    
    sort(add.begin(), add.end());
    
    for(auto u: add){
        int fa = find(u.a), fb = find(u.b);
        if(fa != fb){
            par[fb] = fa;
            if(qu[fa].size() < qu[fb].size()) swap(qu[fa], qu[fb]);
            for(auto r: qu[fb]){
                if(find(r.first) == find(fa) && !ans[r.second])
                    ans[r.second] = u.c;
            }
            qu[fa].insert(qu[fa].end(), qu[fb].begin(), qu[fb].end());
        }
    }
    
    for(int i = 0; i < qr; i++)
        print(ans[i]);
    
    return 0;
}