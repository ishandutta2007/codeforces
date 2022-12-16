#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;
int a[N], b[N];
int aa[N], bb[N];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        aa[a[i]] = i;
    }
    for (int i=0; i<n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    int m = n+1;
    for (int i=n-1; i>=0; --i) {
        bb[i] = aa[b[i]];
        if (m < bb[i]) {
            ++ans;
        }
        m = min(m, bb[i]);
    }
    cout << ans << endl;
    return 0;
}