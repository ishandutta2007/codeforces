#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n, k, cn;

unordered_map<ll, ll> mp;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pii getpair(ll x) {
    ll r = x/(k-1);
    ll p = x-(r*(k-1));
    if(p >= r) p++;
    pii ans(r+1, p+1);
    ////cerr << " " << ans.first << " " << ans.second << endl;
    return ans;
}

ll getval(pii x) {
    ll a = (x.first-1)*(k-1) + (x.second-(x.second > x.first)-1);
    return a;
}

ll gr() {
    return (((ll) rng())^(((ll) rng())<<30))%cn;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    cn = k*(k-1);
    if(cn < n) {

        cout << "NO\n";
        return 0;
    }
    /*
    while(true) {
        int a;
        cin >> a;
        getpair(a);
    } */
    vector<pii> v(n, pii(-1, -1));
    queue<int> bad;
    for(int i=0;i<n;++i) {
        mp[i] = i;
        //cerr << getpair(i).first << " " << getpair(i).second << endl;
        v[i] = getpair(i);
        bad.push(i);
    }
    while(!bad.empty()) {
        int i = bad.front();bad.pop();
        if(i < 0 || i >= n) continue;
        if((i != 0 && (v[i].first == v[i-1].first || v[i].second == v[i-1].second)) || 
            (i != n-1 && (v[i].first == v[i+1].first || v[i].second == v[i+1].second))) {
            ll r = gr()%cn;
            if(mp.count(r)) {
                int o = mp[r];
                swap(v[o], v[i]);
                mp[r] = i;
                mp[getval(v[o])] = o;
                bad.push(i);
                bad.push(o);
            } else {
                auto t = v[i];
                v[i] = getpair(r);
                mp.erase(getval(t));
                mp[r] = i;
                bad.push(i);
            }
        }
    }
    cout << "YES" << endl;
    for(int i=0;i<n;++i) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}