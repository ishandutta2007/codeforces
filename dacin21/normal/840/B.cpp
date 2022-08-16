#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

vector<int> d;
vector<char> v;
vector<int> er;
vector<vector<pair<int, int> > > g;

int dfs(int c){
    v[c]=1;
    int r = (d[c]!=-1 && (d[c]+(int)g[c].size())%2);
    for(auto const&f:g[c]){
        auto const&e=f.first;
        if(!v[e]){
            int b = dfs(e);
            r^=b;
            if(b) er.emplace_back(f.second);
        }
    }
    return r;
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

    ///CODE
    int n, m;
    cin >> n >> m;
    g.clear(); g.resize(n);
    d.assign(n, 0);
    v.assign(n, 0);
    er.clear();
    for(auto &e:d) cin >> e;
    for(int i=1;i<=m;++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    int s=-1;
    for(int i=0;i<n;++i) if(d[i] == -1) s=i;
    bool fail = dfs(max(0, s)) && (s==-1);
    if(fail){
        cout << "-1\n";
    } else {
        vector<int> e(m);
        iota(e.begin(), e.end(), 1);
        vector<int> o;
        sort(er.begin(), er.end());
        set_difference(e.begin(), e.end(), er.begin(), er.end(), back_inserter(o));
        cout << o.size() << "\n";
        for(auto const&f:o){
            cout << f << "\n";
        }
    }

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}