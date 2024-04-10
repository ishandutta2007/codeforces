#include<bits/stdc++.h>

using namespace std;

#define sz(v) ((int)v.size())
#define long long long 
#define ii pair<int, int>
#define inf(t) numeric_limits<t>::max()
#define xx first
#define yy second

int n;
string home;

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n >> home;
    int h, c; h = c = 0;
    while (n--) {
        string s; cin >> s;
        if (s.substr(0, 3) == home) h++;
        if (s.substr(5) == home) c++;
    }

    if (c == h) cout << "home";
    else cout << "contest";

    return 0;
}