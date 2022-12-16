#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 100100;
int f[N*2];
int a[N*2];

#define nl "\n"

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n;
        cin >> n;
        int rc = 0, bc = 0;
        for (int i=1; i<=2*n; ++i) {
            cin >> a[i];
        }
        for (int i=1; i<=2*n; ++i) {
            rc += (a[i] == 1);
            bc += (a[i] == 2);
            if (i <= n) {
                f[N+rc-bc] = i;
                assert(N+rc-bc <= N+n);
                assert(N+rc-bc >= N-n);
            }
        }
        if (rc == bc) {
            for (int i=N-n; i<=N+n; ++i) {
                f[i] = 0;
            }
            cout << 0 << nl;
            //cerr << endl;
            continue;
        }
        int best = 2*n;
        //cerr << " INIT TO " << best << endl;
        rc = 0; bc = 0;
        for (int i=2*n; i>=n; --i) {
            //cerr << "  BEST " << best << endl;
            if (f[N+bc-rc]) {
                best = min(best, i-f[N+bc-rc]);
                //cerr << "! " << i << " " << f[N+bc-rc] << " ?? " << N+bc-rc << endl;
            } else if (rc == bc) {
                best = min(best, i);
                //cerr << "- " << i << endl;
            }

            rc += (a[i] == 1);
            bc += (a[i] == 2);
        }
        cout << best << nl;

        for (int i=N-n; i<=N+n; ++i) {
            f[i] = 0;
        }

    }

    return 0;
}