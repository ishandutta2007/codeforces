#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    vector<pii> ord(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        ord[i] = pii(a[i], i);
    }
    vector<bool> good(n, false);
    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());
    for(int i=0;i<m*k;++i) {
        good[ord[i].second] = 1;
    }
    ll ans = 0;
    ll cnt = 0;
    vector<int> ind;
    for(int i=0;i<n;++i) {
        if(good[i]) {
            if(++cnt%m == 0) {
                ind.push_back(i+1);
            }
            ans += a[i];
        }
    }
    cout << ans << "\n";
    for(int i=0;i<k-1;++i) {
        cout << ind[i] << " ";
    }
    cout << "\n";
    return 0;
}