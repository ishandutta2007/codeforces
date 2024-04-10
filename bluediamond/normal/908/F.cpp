#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300000 + 7;
const ll OO = (ll) 1e18;
int n;
ll x[N];
string c[N];
vector<ll> red;
vector<ll> blue;
vector<ll> green;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> x[i] >> c[i];
                if (c[i] == "R") {
                        red.push_back(x[i]);
                }
                if (c[i] == "B") {
                        blue.push_back(x[i]);
                }
                if (c[i] == "G") {
                        green.push_back(x[i]);
                }
        }
        if (green.empty()) {
                ll cost = 0;
                if (!red.empty()) {
                        cost += red.back() - red[0];
                }
                if (!blue.empty()) {
                        cost += blue.back() - blue[0];
                }
                cout << cost << "\n";
                return 0;
        }
        if (blue.empty()) {
                cout << x[n] - x[1] << "\n";
                return 0;
        }
        if (red.empty()) {
                cout << x[n] - x[1] << "\n";
                return 0;
        }
        green.push_back(-OO);
        green.push_back(+OO);
        sort(green.begin(), green.end());
        set<ll> set_red;
        set<ll> set_blue;
        for (auto &x : red) {
                set_red.insert(x);
        }
        for (auto &x : blue) {
                set_blue.insert(x);
        }
        ll sol = 0;
        for (int pos = 0; pos + 1 < (int) green.size(); pos++) {
                ll l = green[pos];
                ll r = green[pos + 1];
                ll len = r - l;
                red.clear();
                blue.clear();
                auto it = set_red.lower_bound(l);
                while (it != set_red.end() && *it <= r) {
                        red.push_back(*it);
                        it++;
                }
                it = set_blue.lower_bound(l);
                while (it != set_blue.end() && *it <= r) {
                        blue.push_back(*it);
                        it++;
                }
                int sz_red = (int) red.size();
                int sz_blue = (int) blue.size();
                ll cost = 0;
                if (sz_red) {
                        cost += len;
                        red.push_back(l);
                        red.push_back(r);
                        sort(red.begin(), red.end());
                        ll mx = 0;
                        for (int i = 1; i < (int) red.size(); i++) {
                                mx = max(mx, red[i] - red[i - 1]);
                        }
                        cost -= mx;
                }
                if (sz_blue) {
                        cost += len;
                        blue.push_back(l);
                        blue.push_back(r);
                        sort(blue.begin(), blue.end());
                        ll mx = 0;
                        for (int i = 1; i < (int) blue.size(); i++) {
                                mx = max(mx, blue[i] - blue[i - 1]);
                        }
                        cost -= mx;
                }
                if (l != -OO && r != OO) {
                        cost += len;
                }
                sol += min(cost, 2 * len);
        }
        cout << sol << "\n";
}