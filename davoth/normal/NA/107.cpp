// ~ Be Name Khoda ~

// Harf ke nazanim... 
// Zende bemoonim?
// Ya oonm na?
#pragma GCC optimize("O0")

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb       push_back
#define mp       make_pair
#define all(x)   x.begin(), x.end()
#define fi       first
#define se       second

const int maxn  =  1e6   + 10;
const int maxn5 =  5e5   + 10;
const int maxnt =  1.2e6 + 10;
const int maxn3 =  1e3   + 10;
const int mod   =  1e9   +  7;
const ll  inf   =  1e18;

ll dp[2][maxn5], a[maxn5];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        string s; cin >> s;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        dp[1][0] = dp[0][0] = 0;
        if(s[0] == '1')
            dp[1][0] = a[0];
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[1][i] = 0;
            dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
            if(s[i] == '1')
                dp[0][i] = max(dp[0][i], dp[0][i - 1] + a[i - 1]);
            if(s[i] == '1')
                dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + a[i];
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
}