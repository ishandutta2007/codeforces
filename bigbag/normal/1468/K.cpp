/**
 *  created: 25/12/2020, 14:07:24
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

int t;
string s;

pair<int, int> proc(int badx, int bady) {
    int x = 0, y = 0;
    for (char c : s) {
        int nx = x, ny = y;
        if (c == 'L') {
            --nx;
        } else if (c == 'R') {
            ++nx;
        } else if (c == 'U') {
            ++ny;
        } else {
            --ny;
        }
        if (nx == badx && ny == bady) {
            continue;
        }
        x = nx;
        y = ny;
    }
    return {x, y};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        pair<int, int> ans(0, 0);
        int x = 0, y = 0;
        for (char c : s) {
            int nx = x, ny = y;
            if (c == 'L') {
                --nx;
            } else if (c == 'R') {
                ++nx;
            } else if (c == 'U') {
                ++ny;
            } else {
                --ny;
            }
            x = nx;
            y = ny;
            if ((x != 0 || y != 0) && proc(x, y) == make_pair(0, 0)) {
                ans = {x, y};
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}