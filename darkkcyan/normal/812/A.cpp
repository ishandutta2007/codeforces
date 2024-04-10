#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int has_pad[4] = {0}, has_cross[4] = {0};
    rep(i, 4) {
        int a, b, c; cin >> a >> b >> c >> has_pad[i];
        if (c) has_cross[(i + 1) % 4] = 1;
        if (b) has_cross[(i + 2) % 4] = 1;
        if (a) has_cross[(i + 3) % 4] = 1;
        if (a or b or c) has_cross[i] = 1;
    }

    rep(i, 4) if (has_pad[i] and has_cross[i]) {
        clog << i << endl;
        cout << "YES";
        return 0;
    }
    cout << "NO";

    return 0;
}