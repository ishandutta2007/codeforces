#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 8;
int n;
ll a[N];
int pd[N];
vector<ll> vals;
int cost;
int cnt;
int pos;
int ans = (int) 1e9;

void dfs() {
        if (pos == n) {
                ans = min(ans, n + cost + (cnt > 1));
                return;
        }
        for (int i = 0; i < (int) vals.size(); i++) { /// de cine leg
                if (vals[i] % a[pos] == 0) { /// leg de nod sau leg de "radacina"
                        vals[i] /= a[pos];
                        vals.push_back(a[pos]);
                        if (i == 0) {
                                cnt++;
                                cost += pd[pos];
                        }
                        if (pd[pos] == 0 && i) {
                                cost--;
                        }
                        pos++;
                        dfs();
                        pos--;
                        if (pd[pos] == 0 && i) {
                                cost++;
                        }
                        if (i == 0) {
                                cnt--;
                                cost -= pd[pos];
                        }
                        vals.pop_back();
                        vals[i] *= a[pos];
                }
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        for (int i = 0; i < n; i++) {
                ll x = a[i];
                for (ll d = 2; d * d <= x; d++) {
                        while (x % d == 0) {
                                pd[i]++;
                                x /= d;
                        }
                }
                if (x != a[i] && x > 1) {
                        pd[i]++;
                }
        }
        vals.push_back(0);
        dfs();
        cout << ans << "\n";
}