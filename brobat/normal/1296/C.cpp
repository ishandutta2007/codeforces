#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> m;
    m[{0,0}] = 0;
    int loop_length = MOD;
    pair<int, int> rem;
    int x = 0;
    int y = 0;
    forn(i, n) {
        if(s[i]=='R') x += 1;
        if(s[i]=='L') x -= 1;
        if(s[i]=='U') y += 1;
        if(s[i]=='D') y -= 1;
        int temp;
        if(x==0&&y==0) {
            temp = m[{0,0}];
            m[{0,0}] = i + 1;
            if(m[{x, y}] - temp < loop_length) {
                rem.first = temp + 1;
                rem.second = m[{x,y}];
                loop_length = m[{x, y}] - temp;
            }
        }
        else if(m[{x, y}] != 0) {
            temp = m[{x, y}];
            m[{x, y}] = i + 1;
            if(m[{x, y}] - temp < loop_length) {
                rem.first = temp + 1;
                rem.second = m[{x,y}];
                loop_length = m[{x, y}] - temp;
            }
        }
        else {
            m[{x, y}] = i + 1;
        }
    }
    if(loop_length==MOD) cout << -1;
    else cout << rem.first << " " << rem.second;
    cout << endl;
}
    return 0;
}