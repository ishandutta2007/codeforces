#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;
const int mod = int(1e9) + 7;

int n;
vector<ll> a, b;
int ma = 0, id = 0;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    int k = 0;
    int mi = int(1e9);
    forn (i, n) {
        cin >> a[i];
        if (a[i]) k++;
        if (mi > a[i]) mi = a[i];
        if (a[i] > ma) {
            id = i;
            ma = a[i];
        }
    }
    if (k == 1) {
        cout << "YES\n";
        forn (i, n) {
            if (a[i]) cout << a[i] << " ";
            else
                cout << 2 * ma << " ";
        }
        return 0;
    }
    if (ma == 0) {
        cout << "YES\n";
        forn (i, n) cout << 1 << " ";
        cout << "\n";
        return 0;
    }
    if (mi == ma) {
        cout << "NO\n";
        return 0;
    }
    forn (i, n) {
        if (a[i] == ma && a[(i + n - 1) % n] != ma) {
            id = i;
        }
    }
    b[id] = a[id];
    if (id == 0) {
        if (a[n - 1] == 0)
            b[n - 1] = a[0] + a[0];
        else
            b[n - 1] = a[0] + a[n - 1];
    } else {
        if (a[id - 1] == 0) 
            b[id - 1] = 2LL * b[id];
        else
            b[id - 1] = b[id] + a[id - 1];
    }
    for (ll i = id - 2; i >= 0; i--) {
        b[i] = b[i + 1] + a[i];
    }
    for (int i = n - 1 - (id == 0 ? 1 : 0); i > id; i--) {
        b[i] = b[(i + 1) % n] + a[i];
    }

    forn (i, n) {
        if (b[i] % (b[(i + 1) % n]) != a[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    forn (i, n) cout << b[i] << " ";
    cout << "\n";
    return 0;
}