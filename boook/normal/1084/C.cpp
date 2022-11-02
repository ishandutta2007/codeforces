#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 100000 + 10
#define inf 0x3f3f3f3f
#define mod 1000000007ll

string s;
int dp[maxn], pre[maxn];

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> s, s = " " + s;    

    int gap = 0, ans = 0;

    dp[0] = pre[0] = 1;
    for (int i = 1; i < s.size(); ++ i) {
        if (s[i] == 'a') {
            dp[i] = pre[gap];
            ans = (ans + dp[i]) % mod;        
        }
        else if (s[i] == 'b') gap = i;
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}