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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1), can(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        reverse(ALL(a));
        a[0] = 0;
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; i++)
            can[i] = 1;
        for (int k = 2; ; k++) {
            ll mx = 0;
            vector<ll> tmp(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                if (i >= k && can[i - k])
                    mx = max(mx, a[i - k] - a[i - k - (k - 1)]);
                if (i >= k && a[i] - a[i - k] < mx)
                    tmp[i] = 1;
            }
            can.swap(tmp);
            bool ok = 0;
            for (int i = 0; i <= n; i++)
                if (can[i])
                    ok = 1;
            if (!ok) {
                cout << k - 1 << endl;
                break;
            }
        }
         
    }
}