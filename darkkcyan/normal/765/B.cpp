#include<bits/stdc++.h>

using namespace std;

#define sz(v) ((int)v.size())
#define long long long 
#define ii pair<int, int>
#define inf(t) numeric_limits<t>::max()
#define xx first
#define yy second

string s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> s;
    char curchar = 'a' - 1;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == curchar + 1) {
            ++curchar;
        }
        else if (s[i] > curchar + 1) {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";

    return 0;
}