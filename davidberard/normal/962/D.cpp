#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

map<ll, set<int>> mp;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N; cin >> N;
    vector<bool> ok(N, true);
    vector<ll> v;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    set<ll> in_pq;
    for(int i=0;i<N;++i) {
        int ii;
        cin >> ii;
        if(mp.count(ii) == 0) {
            mp[ii] = set<int>();
        }
        mp[ii].insert(i);
        v.push_back(ii);
    }
    for(const auto& pp : mp) {
        if(pp.second.size() > 1) {
            pq.push(pii(pp.first, pp.first));
            in_pq.insert(pp.first);
        }
    }
    while(!pq.empty()) {
        pii t = pq.top(); pq.pop();
        ll val = t.second;
        in_pq.erase(val);
        ok[*(mp[val].begin())] = false;
        mp[val].erase(mp[val].begin());

        int ind_2 = *(mp[val].begin());
        mp[val].erase(mp[val].begin());

        v[ind_2]*=2;
        if(mp.count(val*2) == 0) {
            mp[val*2] = set<int>();
        }
        mp[val*2].insert(ind_2);

        if(mp.count(val) && mp[val].size() > 1 && !in_pq.count(val)) {
            pq.push(pii(val, val));
            in_pq.insert(val);
        }
        if(mp.count(val*2) && mp[val*2].size() > 1 && !in_pq.count(val*2)) {
            pq.push(pii(val*2, val*2));
            in_pq.insert(val*2);
        }
    }
    vector<ll> ans;
    for(int i=0;i<N;++i) {
        if(ok[i]) ans.push_back(v[i]);
    }
    cout << ans.size() << endl;
    for(ll& ii: ans) {
        cout << ii << " ";
    }
    cout << endl;

    return 0;
}