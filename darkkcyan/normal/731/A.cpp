#include <bits/stdc++.h>

#define fn "a"
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

    string s; cin >> s;
    char cur = 'a';
    int ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        int t = (s[i] - cur + 26) % 26;
        ans += min(t, 26 - t);
        cur = s[i];
    }

    cout << ans;

    return 0;
}