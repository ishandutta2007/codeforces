#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    string s, t;
    cin >> s >> t;
    string ans = "";
    int a = 0, b = 0, c = 0;
    forn(i, 0, s.length()) {
        if(s[i]=='a') a++;
        if(s[i]=='b') b++;
        if(s[i]=='c') c++;
    }
    if(t == "abc" && a > 0 && b > 0 && c > 0) t = "acb";
    else t = "abc";
    
    if(t=="acb") {
        forn(i, 0, a) cout << "a";
        forn(i, 0, c) cout << "c";
        forn(i, 0, b) cout << "b";
    }
    else {
        forn(i, 0, a) cout << "a";
        forn(i, 0, b) cout << "b";
         forn(i, 0, c) cout << "c";
    }
    vector <char> v;
    forn(i, 0, s.length()) {
        if(s[i]!='a' && s[i]!='b' && s[i]!='c') v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    for(auto i : v) cout << i;
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}