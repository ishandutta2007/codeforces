#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 20;
const int MOD = 1000000007;

int n, m, k;
char arr[MAXN][MAXN];

bool check(int x, int y, int d) {
    // Can a tick of size d be made with (x, y) as center or not?
    forn(h, 0, d + 1) {
        // if((x-h)<0||(x-h)>=n||(y-h)<0||(y+h)>=m) cout << "F";
        if(arr[x-h][y+h]=='.' || arr[x-h][y-h]=='.') {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m >> k;
    char t;
    int num_painted = 0;
    forn(i, 0, n) forn(j, 0, m) {
        cin >> t;
        arr[i][j] = t;
        if(t=='*') num_painted++;
    }
    map<pair<int, int>, bool> done;
    forn(d, k, min(n, m) + 1) {
        forn(x, d, n) {
            forn(y, d, m - d) {
                if(check(x, y, d)) {
                    forn(h, 0, d + 1) {
                        done[{x-h, y+h}] = true;
                        done[{x-h, y-h}] = true;
                    }
                }
            }
        }
    }
    int pos = 0;
    for(auto i : done) {
        if(i.second == true) pos++;
    }
    if(pos==num_painted) cout << "YES" << endl;
    else cout << "NO" << endl;
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