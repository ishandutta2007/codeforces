#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

constexpr int inf = 1e9;

int n;
vector<vector<int> > g;

vector<pair<int, int> > bfs(int u){
    vector<pair<int, int> > ret(n, make_pair(inf, -1));
    ret[u] = make_pair(0, -2);
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();q.pop();
        for(auto const&e:g[u]){
            if(ret[e]>ret[u]){
                ret[e] = make_pair(ret[u].first+1, u);
                q.push(e);
            }
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

    cin >> n;
    g.assign(n, vector<int>());
    for(int i=1;i<n;++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int c = 0;
    vector<pair<int, int> > dc;
    for(int _:{0, 1, 2}){ (void)_;
        dc = bfs(c);
        c = max_element(dc.begin(), dc.end()) - dc.begin();
    }
    vector<char> isp(n, 0);
    vector<int> path;
    for(int i=c;i!=-2;i=dc[i].second){
        path.push_back(i);
        isp[i] = 1;
    }
    int a = path.back();
    dc = bfs(c);
    auto da = bfs(a);
    //cerr << c << " / " << a << "\n";
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int const&i, int const&j){return da[i]>da[j];});
    stringstream sout;
    ll ans = 0;
    for(auto &i:ord){
        if(!isp[i]){
            //cerr << i << " : " << da[i].first << " / " << dc[i].first << "\n";
            int j = (da[i]>dc[i] ? a : c);
            ans+=max(da[i].first, dc[i].first);
            sout << 1+i << " " << 1+j << " " << 1+i << "\n";
        }
    }

    for(int i=0;i<n;++i){
    }
    for(auto &e:path){
        if(e!=a){
            ans+=da[e].first;
            sout << 1+e << " " << 1+a << " " << 1+e << "\n";
        }
    }
    cout << ans << "\n";
    cout << sout.str() << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}