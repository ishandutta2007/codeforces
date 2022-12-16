#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 400400;

int p[N], f[N];
int n;

void solve() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> p[i];
    }
    p[n+1] = -1;
    int k = 0;
    memset(f, 0, sizeof(int)*(n+2));
    int last = 1e9;
    int count = 0;
    for (int i=1; i<=n+1; ++i) {
        if (p[i] != last) {
            f[k++] = count;
            last = p[i];
            count = 0;
        }
        ++count;
    }
    int j = 2;
    int amt = f[1];
    int silver = 0, bronze = 0;
    while (amt+f[j] <= n/2 && silver <= f[1] && j < k) {
        amt += f[j];
        silver += f[j];
        ++j;
    }
    while (amt+f[j] <= n/2 && bronze <= f[1] && j < k) {
        amt += f[j];
        bronze += f[j];
        ++j;
    }

    while (amt+f[j] <= n/2 && j<k) {
        amt += f[j];
        bronze += f[j];
        ++j;
    }

    //cerr << " g s b " << f[1] << " " << silver << " " << bronze << endl;
    if (f[1] < silver && f[1] < bronze) {
        cout << f[1] << " " << silver << " " << bronze << "\n";
    } else {
        cout << "0 0 0\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}