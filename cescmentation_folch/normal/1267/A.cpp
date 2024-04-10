#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> VI;
typedef vector<VI> VVI;

const ll INF = 2e18+100;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    VI a(n), b(n), t(n);
    
    vector<ii> evs;
    for (int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> t[i];
        evs.push_back({a[i], (i+1)});
        evs.push_back({b[i]-t[i]+1, -(i+1)});
    }
    sort(evs.begin(), evs.end());
    
    ll nxt = INF, cur = 0, res = 0;
    set<ii> espases;
    int i = 0;
    while (i < int(evs.size())){
        if (nxt <= evs[i].first){
            cur = nxt;
            nxt = INF;
            ++res;
            if (espases.size() != 0){
                ll l = espases.begin()->first;
                res += (evs[i].first-cur)/l;
                if ((evs[i].first-cur)%l != 0)
                    nxt = evs[i].first + l-(evs[i].first-cur)%l;
                cur = evs[i].first;
            }
        }
        else{
            cur = evs[i].first;
            while (i < int(evs.size()) and evs[i].first == cur){
                int x = evs[i].second;
                if (x > 0) espases.insert({t[x-1], x});
                else espases.erase({t[-x-1], -x});
                ++i;
            }
            if (espases.size() != 0){
                nxt = min(nxt, cur+espases.begin()->first);
            }
        }
    }
    if (nxt != INF) ++res;  
        
    cout <<res << endl;
    
}