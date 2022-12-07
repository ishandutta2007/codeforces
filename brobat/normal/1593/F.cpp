#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
// const int INF = 9100000000000000000;
const double EPS = 1E-7;

/*
Choose last d digits.
Paint x of them red (rest d - x are blue).
Say that these digits make the number a modulo A and the remaining make the number b modulo B.

dp[d][x][a][b] --> True if this is possible.

Now choose the (d + 1)th digit. Either paint this red or blue. 

Transition --> O(n^3) as "d" remains the same (transition from dp[d][][][] to dp[d+1][][][])
*/

int binpow(int a, int b, int MOD) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s; cin >> s;
    int dp[n][n+1][a][b]; // 0--> false. 1--> color current digit RED. 2 --> color current digit BLACK. 
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][(s[n-1] - '0') % b] = 2;
    dp[0][1][(s[n-1] - '0') % a][0] = 1;
    int p[n][n+1][a][b]; // previous state
    // memset(p, 0, sizeof(p));
    int curr, temp;
    for(int d = 1; d < n; d++) {
        curr = s[n - 1 - d] - '0';
        // Build dp[d] based on dp[d - 1] and s[n - 1 - d] * binpow(10, digits, MOD).
        for(int x = 0; x <= d; x++) {
            // x digits are currently painted red
            for(int y = 0; y < a; y++) {
                for(int z = 0; z < b; z++) {
                    // y mod a, z mod b.
                    if(dp[d - 1][x][y][z] > 0) {
                        temp = (y + binpow(10, x, a) * curr) % a;
                        dp[d][x+1][temp][z] = 1;
                        p[d][x+1][temp][z] = y;
                        temp = (z + binpow(10, d - x, b) * curr) % b;
                        dp[d][x][y][temp] = 2;
                        p[d][x][y][temp] = z;
                    }
                }
            }
        }
    }
    vector<int> order;
    for(int diff = n % 2; diff < n; diff += 2) {
        int x = (n + diff)/2;
        order.push_back(x);
        x = (n - diff)/2;
        order.push_back(x);
    }
    for(auto o : order) {
        if(dp[n - 1][o][0][0] != 0) {
            int d = n - 1;
            int x = o;
            int y = 0;
            int z = 0;
            string ans;
            while(d >= 0) {
                // cout << d << " " << x << " " << y << " " << z << " " << dp[d][x][y][z] << endl;
                if(dp[d][x][y][z] == 1) {
                    ans += "R";
                    y = p[d][x][y][z];
                    x--;
                }
                else {
                    ans += "B";
                    z = p[d][x][y][z];
                }
                d--;
            }
            // cout << o << " " << ans << endl;
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}