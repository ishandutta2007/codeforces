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


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n - 1; ++i) printf("%d ", a[i] + a[i + 1]);
    printf("%d", a[n - 1]);

    return 0;
}