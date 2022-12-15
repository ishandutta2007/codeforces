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

bool solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v, v2;
    for (int i = 0, a; i < n; i++)
        cin >> a, v.pb(a);
    v2 = v;
    sort(ALL(v2));
    for (int i = 0; i < n; i++)
        if (i - x < 0 && i + x >= n && v[i] != v2[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
}