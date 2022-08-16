#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

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

    int n, w, h;
    cin >> n >> w >> h;
    vector<array<int, 3> > dan(n);

    map<int, vector<int> > bu;

    for(auto &e:dan){
        cin >> e[0] >> e[1] >> e[2];
    }
    for(int i=0;i<n;++i){
        auto const&e = dan[i];
        bu[e[1] - e[2]].push_back(i);
    }
    vector<pair<int, int> > ans(n, make_pair(-1, -1));
    for(auto const&e:bu){
        vector<pair<int, int> > tmp;
        vector<pair<int, int> > tmp2;
        for(int i:e.second){
            auto const&f = dan[i];
            if(f[0] == 1){
                tmp.emplace_back(f[1], i);
                tmp2.emplace_back(f[1], i);
            } else {
                tmp.emplace_back(-f[1], i);
                tmp2.emplace_back(2*(w+h)-f[1], i);
            }
        }
        sort(tmp.begin(), tmp.end());
        sort(tmp2.begin(), tmp2.end());
        for(int i=0;i<(int)tmp.size();++i){
            auto const&f = dan[tmp2[i].second];
            pair<int, int> pos(-1, -1);
            if(f[0] == 1){
                pos = make_pair(f[1], h);
            } else {
                pos = make_pair(w, f[1]);
            }
            ans[tmp[i].second] = pos;
        }
    }
    for(auto const&e:ans){
        cout << e.first << " " << e.second << "\n";
    }




    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}