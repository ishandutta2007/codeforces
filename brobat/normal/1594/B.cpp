#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

string decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    string s = "";
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        // cout << binaryNum[j];
        s += to_string(binaryNum[j]);
    return s;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s = decToBinary(k);
    int pw[32];
    pw[0] = 1;
    forn(i, 1, 32) pw[i] = (pw[i-1] * n) % MOD;
    int ans = 0;
    forn(i, 0, s.length()) {
        if(s[i]=='0') continue;
        ans = (ans + (pw[s.length() - i - 1])) % MOD;
    }
    cout << ans << endl;
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