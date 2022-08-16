#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

vector<vector<pair<int, int> > > g;

vector<int> eu;
vector<int> cured;

void rec(int u){
    for(int&i=cured[u];i<(int)g[u].size();){
        int v = g[u][i].first;
        int x = g[u][i].second;
        ++i;
        //cerr << u << " -> " << v << " : " << x << "\n";
        rec(v);
        eu.push_back(x);
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

    int n, s;
    cin >> n >> s;
    vector<int> a(n), b;
    for(auto &e:a){
        cin >> e;
    }
    b = a;
    sort(b.begin(), b.end());
    for(auto &e:a){
        e = lower_bound(b.begin(), b.end(), e) - b.begin();
    }
    b = a;
    sort(b.begin(), b.end());
    /*vector<int> l(n, -1);
    for(int i=0;i<n;++i){
        if(l[a[i]] == -1){
            l[a[i]] = i;
        }
    }*/

    g.clear();
    g.resize(n);
    for(int i=0;i<n;++i){
        if(a[i] != b[i]){
            //cerr << a[i] << " -> " << b[i] << " " << i << "\n";
            g[a[i]].emplace_back(b[i], i);
        }
    }
    vector<vector<int> > cyc;
    int tot = 0;
    cured.assign(n, 0);
    for(int i=0;i<n;++i){
        eu.clear();
        rec(i);
        if(!eu.empty()){
            cyc.push_back(eu);
            tot+=eu.size();
        }
    }
    if(tot > s){
        cout << "-1\n";
    } else {
        int spare = s - tot;
        if(spare > 2 && cyc.size()>2){
            xmin(spare, (int)cyc.size());
            vector<int> big, small;
            for(int i=0;i<spare;++i){
                small.push_back(cyc.back().back());
                big.insert(big.end(), cyc.back().begin(), cyc.back().end());
                cyc.pop_back();
            }
            reverse(small.begin(), small.end());
            cyc.push_back(small);
            cyc.push_back(big);
        }
        cout << cyc.size() << "\n";
        for(auto const&e:cyc){
            cout << e.size() << "\n";
            for(auto const&f:e){
                cout << 1+f << " ";
            }
            cout << "\n";
        }
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}