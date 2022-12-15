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

int ca[212345], cb[212345], x[212345], y[212345];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int a, b, k;
        cin >> a >> b >> k;
        ll tt = 0;
        for (int i = 1; i <= a; i++)
            ca[i] = 0;
        for (int i = 1; i <= b; i++)
            cb[i] = 0;
        for (int i = 1; i <= k; i++)
            cin >> x[i];
        for (int i = 1; i <= k; i++)
            cin >> y[i];
        for (int i = 1; i <= k; i++) {
            tt += i - 1 - ca[x[i]] - cb[y[i]];
            ca[x[i]]++, cb[y[i]]++;
        }
        cout << tt << "\n";
    }
}