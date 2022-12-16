#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int a[55][55];
int p[55];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> a[i][j];
        }
    }
    bool have = false;
    for(int i=1; i<=n; ++i) {
        int mx = 0;
        for(int j=1; j<=n; ++j) {
            if(i == j) continue;
            mx = max(a[i][j], mx);
        }
        if(mx == n-1) {
            if(!have) {
                p[i] = mx;
                have = true;
            } else {
                p[i] = mx+1;
            }
        } else {
            p[i] = mx;
        }
    }
    for(int i=1; i<=n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}