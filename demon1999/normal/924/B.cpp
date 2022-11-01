#include <bits/stdc++.h>
 
 
using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int ma = 1024 * 1024;

ll n, u;
vector<ll> a;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    cin >> n >> u;
    a.resize(n);
    forn (i, n) cin >> a[i];
    double ans = -1;
    int j = 2;
    forn (i, n) {
        while (j < n && a[j] - a[i] <= u) j++;
        if (j - 1 > i + 1) {
            ans = max(ans, double(a[j - 1] - a[i + 1]) / double(a[j - 1] - a[i]));
        }
    }
    if (ans < 0) cout << -1;
    else {
        cout.precision(30);
        cout << ans;
    }
}