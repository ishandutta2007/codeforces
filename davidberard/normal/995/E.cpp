#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

unordered_map<ll, pii> mp;
ll u, v, p;

ll modpow(ll b, ll pw, ll mod=p) {
    ll ans = 1;
    for (; pw; pw/=2, b=b*b%mod) {
        if (pw&1) ans = ans*b%mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> u >> v >> p;

    mp[v] = pii(0, v);
    for (int q=0; q*q <= p; ++q) {
        ll cur = v;
        for (int i=0; i<100; ++i) {
            int r = rng()%3;
            r++;
            ll nxt = 0;
            if (r == 1) {
                //cerr << " :: " << cur + p - 1 << "%" << p << endl;
                nxt = (cur+p-1)%p;
            } else if (r == 2) {
                nxt = (cur+1)%p;
            } else if (r == 3) {
                nxt = modpow(cur, p-2);
            }
            if (!mp.count(nxt)) {
                mp[nxt] = pii(r, cur);
            }
            cur = nxt;
        }
    }

    unordered_set<int> seen;
    vector<pii> history;
    int qc = 0;
    while (true) {
        ll cur = u;
        history.clear();
        for (int i=0; i<100; ++i) {
            int r = rng()%3;
            r++;
            ll nxt = 0;
            if (r == 1) {
                nxt = (cur+1)%p;
            } else if (r == 2) {
                nxt = (cur+p-1)%p;
            } else if (r == 3) {
                nxt = modpow(cur, p-2);
            }
            history.emplace_back(r, nxt);
            cur = nxt;
            if (mp.count(nxt)) {
                vector<int> ans;
                for (auto& x : history) {
                    ans.push_back(x.first);
                    //cerr << "-> " << x.second << endl;
                }
                int x = nxt;
                while (x != v) {
                    ans.push_back(mp[x].first);
                    //cerr << "  (vs " << v << ")" << endl;
                    x = mp[x].second;
                    //cerr << "-> " << x << endl;
                }
                cout << ans.size() << "\n";
                for (auto& x : ans) {
                    cout << x << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}