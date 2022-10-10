#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

char order[] = {'f', 'e', 'd', 'a', 'b', 'c'};
long cnt(long sp, char ch) {
    long ans = 0;
    for (long i = 0; i <= 1; ++i) {
        for (long f = 0; f < 6; ++f) {
            ++ans;
            if (i == sp and order[f] == ch) return ans;
        }
        ++ans;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    long x; char ch; cin >> x >> ch; --x;

    long t = x / 4;
    long ans = t * (cnt(1, 'c') + 3);
    ans += cnt(x % 2, ch);
    cout << ans;

    return 0;
}