#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

// because I use __builtin_popcount to count long long number to much time :|
#define bitcnt(t) __builtin_popcountll(t)

namespace sol {

llong n, t, k, d;

int main() {
    cin >> n >> t >> k >> d;
    llong a = ((n + k - 1) / k) * t;
    llong b = 0;
    multiset<ii> time;
    time.insert({t, 1});
    time.insert({d, 0});
    while (n > 0) {
        int c = time.begin()->xx;
        int type = time.begin()->yy;
        //clog << c << ' ' << type << endl;
        time.erase(time.begin());
        if (type == 1) {
            n -= k;
            b = c;
        }
        time.insert({c + t, 1});
    }
    clog << b << ' ' << a << endl;
    if (b < a) cout << "YES";
    else cout << "NO";
    return 0;
} }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--)
    sol::main();
    return 0;
}