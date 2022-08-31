#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

vector<vector<int> > g, rg;
vector<int> r, mir, mar;
vector<char> vis;

void rec(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for(int e:g[u]){
        rec(e);
        xmax(mir[u], mir[e]+1);
    }
}
void rec2(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for(int e:rg[u]){
        rec2(e);
        xmin(mar[u], mar[e]-1);
    }
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

    int n, m, k;
    cin >> n >> m >> k;
    g.assign(n, vector<int>());
    rg.assign(n, vector<int>());
    r.assign(n, 0);
    mar.assign(n, k);
    mir.assign(n, 1);
    vector<int> rfree(k+1, 1);
    rfree[0]=0;
    for(int i=0;i<n;++i){
        cin >> r[i];
        if(r[i]!=0){
            mir[i] = mar[i]=r[i];
            rfree[r[i]]=0;
        }
    }
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vis.assign(n, 0);
    for(int i=0;i<n;++i){
        rec(i);
    }
    vis.assign(n, 0);
    for(int i=0;i<n;++i){
        rec2(i);
    }
    bool f = false;
    for(int i=0;i<n;++i){
        if(mir[i]<1 || mir[i]>k) f=true;
        if(mar[i]<1 || mar[i]>k) f=true;
        if(mir[i]>mar[i]) f=true;
    }
    if(!f){
        vector<vector<int> > bumi(k+1), buma(k+1);
        for(int i=0;i<n;++i){
            if(r[i] == 0) bumi[mir[i]].push_back(i);
            if(r[i] == 0) buma[mar[i]].push_back(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> ac;
        for(int i=1;i<=k;++i){
            for(int e:bumi[i]){
                ac.emplace(mar[e], e);
            }
            for(auto const&e:buma[i]){
                if(r[e] == 0){
                    r[e] = i;
                    rfree[i] = 0;
                }
            }
            if(!rfree[i]) continue;
            while(!ac.empty()&& r[ac.top().second]!=0) ac.pop();
            if(ac.empty()){
                f=true;
                break;
            } else {
                int u = ac.top().second; ac.pop();
                r[u] = i;
            }
        }
    }
    if(!f){
        for(int i=0;i<n;++i){
            assert(r[i]<=mar[i]);
            assert(r[i]>=mir[i]);
            for(int e:g[i]){
                if(r[e]>=r[i])
                    f=true;
            }
        }
    }
    fill(rfree.begin(), rfree.end(), 0);
    for(int i=0;i<n;++i){
        rfree[r[i]]=1;
    }
    if(!f){
        assert(accumulate(rfree.begin(), rfree.end(), 0) == k);
    }
    if(f){
        cout << "-1\n";
    } else {
        copy(r.begin(), r.end(), ostream_iterator<int>(cout,  " "));
        cout << "\n";
    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}