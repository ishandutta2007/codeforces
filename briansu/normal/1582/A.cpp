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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = 0;
        if (c & 1)
            d = 3;

        if (b && d == 3)
            d -= 2, b--;
        if ((b&1) && !d)
            d = 2;

        if (a < d)
            d -= a;
        else
            d = (a - d) & 1;

        cout << d << "\n";
    }
}