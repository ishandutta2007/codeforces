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

    string s; cin >> s;
    int i;
    for (i = 0; i < sz(s); ++i) if (s[i] != 'a') break;
    if (i == sz(s)) s[sz(s) - 1] = 'z';
    else for (; i < sz(s); ++i) if (s[i] != 'a') --s[i]; else break;
    cout << s;

    return 0;
}