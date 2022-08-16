#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

const ll inf = 1e18;

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
    vector<priority_queue<pair<ll, ll>, vector<pair<ll, ll> > , greater<pair<ll, ll> > > > deps(n);
    vector<ll> ar(n, inf);
    // time, cost, user
    vector<array<ll, 3> > cands;
    int fails = n;
    for(int i=0;i<m;++i){
        ll time, cost;
        int from, to;
        cin >> time >> from >> to >> cost;
        if(from == 0){ // depart
            --to;
            deps[to].push({cost, time-k});
            cands.push_back({time-k, -1-to, cost});
        } else { // arrive
            --from;
            assert(to==0);
            cands.push_back({time, from, cost});
        }
    }
    ll cost = 0;
    for(int i=0;i<n;++i){
        if(deps[i].empty()){
            ++fails;
        } else {
            cost+=deps[i].top().first;
        }
    }
    sort(cands.begin(), cands.end());
    cands.push_back({inf, 0, 0});
    ll ret = inf;
    ll curtime = -inf;
    for(auto &e:cands){
        if(curtime < e[0]){
            //cerr << e[0] << " : " << fails << " / " << cost << "\n";
            if(fails == 0){
                xmin(ret, cost);
            }
            curtime = e[0];
        }
        if(e[1]<0){ // depart
            e[1] = -1-e[1];
            if(!deps[e[1]].empty()){
                cost-=deps[e[1]].top().first;
                while(!deps[e[1]].empty() && deps[e[1]].top().second <= curtime){
                    deps[e[1]].pop();
                }
                if(deps[e[1]].empty()){
                    ++fails;
                } else {
                    cost+=deps[e[1]].top().first;
                }
            }
        } else { // arrive
            if(ar[e[1]] == inf){
                --fails;
            } else {
                cost-=ar[e[1]];
            }
            xmin(ar[e[1]], e[2]);
            cost+=ar[e[1]];
        }
    }
    if(ret == inf) ret = -1;
    cout << ret << "\n";

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}