#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 100100;
int pos[N];
int a[N];
int seen[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n, m;
        cin >> n >> m;

        int sz = n;

        for (int i=1; i<=n; ++i) {
            int x;
            cin >> x;
            pos[x] = n-i+1;
            a[n-i+1] = x;
            seen[i] = 0;
        }
        ll ans = 0;
        int lowest = n+1;
        for (int i=1; i<=m; ++i) {
            int b;
            cin >> b;
            if (seen[b]) {
                //cerr << " INC " << endl;
                ans += 1;
                --sz;
            } else {
                int amt = (sz-lowest+1);
                for (--lowest;;--lowest) {
                    ++amt;
                    seen[a[lowest]] = 1;
                    ////cerr << " A " << lowest << " = " << a[lowest] << endl;
                    if (a[lowest] == b) {
                        break;
                    }
                }
                --sz;
                ////cerr << "AMT " << amt << endl;
                ans += amt*2-1;
                //cerr << " INC " << amt*2-1 << endl;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}