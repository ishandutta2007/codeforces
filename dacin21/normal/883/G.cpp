#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

struct Edge{
    int to;
    int ind;
    char c;
    Edge(int t, int i, char tt):to(t), ind(i), c(tt){}
    Edge(int t, int i, int tt):to(t), ind(i), c(tt){}
};
vector<vector<Edge> > g;
string edir;
vector<char> vis;

int dfs(int u){
    if(vis[u]) return 0;
    int ret=1;
    vis[u] = 1;
    for(auto const&e:g[u]){
        if(edir[e.ind]=='.'){
            edir[e.ind] = e.c;
        }
        if(edir[e.ind] == e.c){
            ret+=dfs(e.to);
        }
    }
    return ret;
}
int dfs2(int u){
    if(vis[u]) return 0;
    int ret=1;
    vis[u] = 1;
    for(auto const&e:g[u]){
        if(edir[e.ind]=='.'){
            edir[e.ind] = (e.c=='+' ? '-' : '+');
        }
        if(edir[e.ind] == e.c){
            ret+=dfs2(e.to);
        }
    }
    return ret;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n, m, s;
    cin >> n >> m >> s;
    g.assign(n, vector<Edge>());
    edir.assign(m, '.');
    --s;
    for(int i=0;i<m;++i){
        int a, b, c;
        cin >> c >> a >> b;
        --a; --b;
        if(c == 1){
            g[a].emplace_back(b, i, '#');
            edir[i] = '#';
        } else {
            g[a].emplace_back(b, i, '+');
            g[b].emplace_back(a, i, '-');
        }
    }
    vis.assign(n, 0);
    auto ed2 = edir;
    int a2 = dfs(s);
    cout << a2 << "\n";
    for(auto &e:edir){
        if(e == '.') cout << '+';
        else if(e=='+') cout << '+';
        else if(e=='-') cout << '-';
    }
    cout << "\n";
    edir = ed2;
    vis.assign(n, 0);
    int a = dfs2(s);
    cout << a << "\n";
    for(auto const&e:edir){
        if(e == '.') cout << '+';
        else if(e=='+') cout << '+';
        else if(e=='-') cout << '-';
    }
    cout << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}