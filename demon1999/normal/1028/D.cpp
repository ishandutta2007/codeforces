#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;
const int mod = int(1e9) + 7;

int n;
vector<pair<int, int> > pq, cq;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int pl = -int(1e9);
    int pr = int(1e9); 
    set<int> ss;
    ss.insert(pl);
    ss.insert(pr);
    int ans = 1;
    forn (i, n) {
        string s;
        int k;
        cin >> s >> k;
        if (s == "ADD") {
            ss.insert(k);
        } else {
            if (k < pl || k > pr) {
                cout << "0\n";
                return 0;
            }
            if (k > pl && k < pr) {
                ans = (ans * 2) % mod;
            }
            auto it = ss.find(k);
            it++;
            pr = (*it);
            it--; it--;
            pl = (*it);
            ss.erase(k);
        }
    }
    ll k = 1;
    for (auto v : ss) {
        if (v > pl && v < pr) {
            k++;
        }
    }
    ans = ll(ans) * k % mod;
    cout << ans;
    return 0;
}