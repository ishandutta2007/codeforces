#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int a[20];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    for (int i=0; i<(1<<n); ++i) {
        int sum = 0;
        for (int j=0; j<n; ++j) {
            int sgn = 1;
            if ((i>>j)&1) sgn = -1;
            sum += sgn*a[j];
        }
        if ((sum+360*360)%360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout <<"NO" << endl;
    return 0;
}