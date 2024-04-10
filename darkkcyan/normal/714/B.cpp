#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

int n;
vi a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.bb, a.ee);
    a.resize(unique(a.bb, a.ee) - a.bb);
    if (a.size() >= 4) return cout << "NO", 0;

    switch (a.size()) {
        case 1:
        case 2:
             return cout << "YES", 0;
        case 3:
            if (a[1] - a[0] == a[2] - a[1]) cout << "YES";
            else cout << "NO";
            return 0;
    }

    return 0;
}