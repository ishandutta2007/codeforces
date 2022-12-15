#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 3e4 + 5;
int a[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        bool ok = true;
        for (int i = 1, mn = a[1], need = 0; i <= n; i++) {
            if (a[i] < need) {
                ok = false;
                break;
            }
            mn = min(mn, a[i] - need);
            if (a[i] - mn > need)
                need = a[i] - mn;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}