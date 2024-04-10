#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 200200;
int epfx[NMAX], opfx[NMAX];
int a[NMAX];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        epfx[i] = epfx[i-1];
        opfx[i] = opfx[i-1];
        if(i&1) {
            opfx[i] += a[i];
        } else {
            epfx[i] += a[i];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i) {
        if(epfx[i-1]+opfx[n]-opfx[i] == opfx[i-1]+epfx[n]-epfx[i]) {
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}