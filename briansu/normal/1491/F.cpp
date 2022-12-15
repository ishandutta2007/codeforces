#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int ask(vector<int> &l, vector<int> &r) {
    cout << "? " << SZ(l) << " " << SZ(r) << "\n";
    for (int i = 0; i < SZ(l); i++)
        cout << l[i] << " \n"[i == SZ(l) - 1];
    for (int i = 0; i < SZ(r); i++)
        cout << r[i] << " \n"[i == SZ(r) - 1];
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int ans[2005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            ans[i] = -1;
        vector<int> l, r(1);
        l.pb(1);
        int target = -1;
        for (int i = 2; i <= n; i++) {
            r[0] = i;
            int res = ask(l, r);
            if (res != 0) {
                target = i;
                ans[target] = 1;
                int lb = 0, rb = i - 1;
                while (lb != rb - 1) {
                    vector<int> l2;
                    int h = (lb + rb) / 2;
                    for (int j = 1; j <= h; j++)
                        l2.pb(j);
                    if (ask(l2, r) != 0) rb = h;
                    else lb = h;
                }
                for (int j = 1; j < i; j++)
                    ans[j] = 0;
                ans[rb] = 1;
                break;
            }
            l.pb(i);
        }
        assert(target != -1);
        l.resize(1);
        for (int i = target + 1; i <= n; i++) {
            l[0] = target, r[0] = i;
            if (ask(l, r) != 0) ans[i] = 1;
            else ans[i] = 0;
        }
        vector<int> tt;
        for (int i = 1; i <= n; i++)
            if (ans[i] == 0)
                tt.pb(i);
        cout << "! " << SZ(tt);
        for (int t : tt)
            cout << " " << t;
        cout << "\n";
        cout.flush();
    }
    
}