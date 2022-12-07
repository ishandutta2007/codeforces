#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int fx = 1, fy = 1; // Final position of robot
    for(auto i : s) {
        if(i == 'R') fy++;
        else fx++;
    }
    int x = n - fx;
    int y = n - fy;
    // ^^ How much the robot can afford to go to
    
    int m = (int)s.length();
    int ans = m + 1; // Original positions
    
    bool found_down = false;
    for(int i = 0; i < m; i++) {
        if(!found_down) {
            if(s[i] == 'D') found_down = true;
            else continue;
        }
        if(s[i] == 'R') ans += x;
    }

    bool found_right = false;
    for(int i = 0; i < m; i++) {
        if(!found_right) {
            if(s[i] == 'R') found_right = true;
            else continue;
        }
        if(s[i] == 'D') ans += y;
    }
    if(found_down && found_right) ans += x + y + x*y;
    else if(found_down && !found_right) ans += x;
    else if(!found_down && found_right) ans += y;
    cout << ans << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}