#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    sort(v.begin(), v.end());
    if (n==1) {
        cout << sum << "\n";
        return 0;
    }
    if (n == 2) {
        cout << sum*2 << "\n";
        return 0;
    }
    ll ans = sum*2;
    for (int i=0; i<n-2; ++i) {
        sum -= v[i];
        ans += sum;
    }
    cout << ans << "\n";

    return 0;
}