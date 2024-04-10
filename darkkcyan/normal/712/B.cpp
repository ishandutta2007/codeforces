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

string s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> s;
    if (s.size() & 1) return cout << "-1", 0;
    int a['Z'] = {0};
    for (char c: s) a[c] ++;
    int ans = (abs(a['L'] - a['R']) + 1) / 2 + abs(a['U'] - a['D']) / 2;
    cout << ans;

    return 0;
}