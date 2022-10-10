#include <bits/stdc++.h>

#define fn "b"
using namespace std;

#ifdef db
#define log(msg) clog << __LINE__ << ": " << msg << endl
#else
#define log(msg)
#endif
#define _ << ' ' <<

#define long long long
#define ve vector
#define vi vector<int>
#define sz(v) ((int) v.size())
typedef pair<int, int> ii;
#define xx first
#define yy second
#define pb push_back
#define itor iterator
#define bb begin()
#define ee end()
#define ln '\n'

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif

    int n; cin >> n;
    bool predis = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        a -= predis;
        if (a < 0) return cout << "NO", 0;
        predis = a % 2;
    }
    if (predis) cout << "NO";
    else cout << "YES";

    return 0;
}