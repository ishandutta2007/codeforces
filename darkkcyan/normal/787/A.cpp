#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {

long a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    if (abs(b - d) % __gcd(a, c)) return cout << "-1", 0;
    for (int i = 0; ; ++i) {
        long time = b + a * i;
        if ((time - d) % c or (time - d) / c < 0) continue;
        cout << time << endl;
        break;
    }

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Sol::main();
}