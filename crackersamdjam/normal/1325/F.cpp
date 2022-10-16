#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

constexpr int MM = 1e5+1, NN = 2e5+1, LOG = 17;

int n, m;
std::vector<int> adj[MM];
int dep[MM], sp[LOG][MM], x[NN], y[NN];
bool vis[MM], used[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v]){
        int z = u;
        u = v;
        v = z;
    }
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

void dfs(int cur, int pre){
    dep[cur] = dep[pre]+1;
    sp[0][cur] = pre;
    vis[cur] = 1;
    for(int u: adj[cur]){
        if(!vis[u])
            dfs(u, cur);
    }
}

std::vector<int> f, s;
int SQ;

std::mt19937 g1(time(0));
int randint(int a, int b){return std::uniform_int_distribution<int>(a, b)(g1);}

std::pair<int, int> p[MM];

int main(){
    scan(n, m);
    SQ = ceil(sqrtl(n));
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        x[i] = a, y[i] = b;
    }
    
    memset(sp, -1, sizeof sp);
    dfs(1, 0);
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j <= n; j++){
            if(~sp[i-1][j])
                sp[i][j] = sp[i-1][ sp[i-1][j] ];
        }
    }
    
    for(int i = 0; i < m; i++){
        int lca = getlca(x[i], y[i]);
        int d = dep[x[i]]+dep[y[i]]-2*dep[lca]+1;
        if(d >= SQ and d > 2){
            while(x[i] != lca){
                f.emplace_back(x[i]);
                x[i] = sp[0][x[i]];
            }
            f.emplace_back(lca);
            while(y[i] != lca){
                s.emplace_back(y[i]);
                y[i] = sp[0][y[i]];
            }
            reverse(s.begin(), s.end());
            for(int j: s)
                f.push_back(j);
            
            print(2);
            print(f.size());
            for(int u: f)
                printn(u), pc(32);
            return 0;
        }
    }
    
    //bfs try
    std::queue<int> q;
    for(int t = 0; t < 20; t++){
        f.clear();
        memset(vis, 0, sizeof vis);
        memset(used, 0, sizeof used);
        int st = randint(1, n);
        q.push(st);
        vis[st] = 1;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            bool b = 0;
            for(int u: adj[cur]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = 1;
                }
                b |= used[u];
            }
            //print(cur, b);
            if(!b){
                used[cur] = 1;
                f.emplace_back(cur);
            }
        }
        if(f.size() >= SQ){
            print(1);
            for(int i = 0; i < SQ; i++)
                printn(f[i]), pc(32);
            return 0;
        }
    }
    
    //try greedy first
    for(int i = 1; i <= n; i++){
        p[i] = {adj[i].size(), i};
    }
    sort(p+1, p+n+1);
    f.clear();
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        int cur = p[i].second;
        for(int u: adj[cur]){
            if(vis[u])
                goto no2;
        }
        vis[cur] = 1;
        f.emplace_back(cur);
        no2:;
    }
    if(f.size() >= SQ){
        print(1);
        for(int i = 0; i < SQ; i++)
            printn(f[i]), pc(32);
        return 0;
    }
    
    //
    
    for(int i = 1; i <= n; i++){
        for(int u: adj[i])
            p[i].first -= (int)adj[u].size();
    }
    sort(p+1, p+n+1);
    f.clear();
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        int cur = p[i].second;
        for(int u: adj[cur]){
            if(vis[u])
                goto no3;
        }
        vis[cur] = 1;
        f.emplace_back(cur);
        no3:;
    }
    if(f.size() >= SQ){
        print(1);
        for(int i = 0; i < SQ; i++)
            printn(f[i]), pc(32);
        return 0;
    }
    
    //
    
    for(int i = 0; i < n; i++)
        x[i] = i+1;
    while(1){
        f.clear();
        memset(vis, 0, sizeof vis);
        shuffle(x, x+n, g1);
        for(int i = 0; i < n; i++){
            for(int u: adj[x[i]]){
                if(vis[u])
                    goto no;
            }
            vis[x[i]] = 1;
            f.emplace_back(x[i]);
            no:;
        }
        if(f.size() >= SQ){
            print(1);
            for(int i = 0; i < SQ; i++)
                printn(f[i]), pc(32);
            return 0;
        }
    }
    
    return 0;
}
/*
5 5
1 2
2 3
1 3
3 4
4 5
 */