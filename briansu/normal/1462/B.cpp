#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const string targ = "2020";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s == targ) {
            cout << "YES" << endl;
            continue;
        }
        int fg = 0;
        for (int i = 0; i + (n - SZ(targ)) <= n; i++)
            if (s.substr(0, i) + s.substr(i + (n - SZ(targ))) == targ) {
                fg = 1;
                break;
            }
        if (fg) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
        
}