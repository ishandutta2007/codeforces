#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i, f, g;

    char c; int d;
    cin >> c >> d;
    c -= 'a';
    d --;
    int a[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    if (c == 0) a[0][0] = a[1][0] = a[2][0] = 0;
    if (c == 7) a[0][2] = a[1][2] = a[2][2] = 0;
    if (d == 0) a[0][0] = a[0][1] = a[0][2] = 0;
    if (d == 7) a[2][0] = a[2][1] = a[2][2] = 0;

    int ans = 0;
    for (i = 0; i < 3; ++i) {
        for (f = 0; f < 3; ++f) {
            ans += a[i][f];
        }
    }

    cout << ans;
    return 0;
}