#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, arr[N], brr[N], dp[N][N][2][2], cnt[N][N][2][2];

void solve(){
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 1; i<=n; ++i){
        if(s1[i-1]=='?') arr[i] = 2;
        else arr[i] = s1[i-1]-'0';
        if((i&1) && arr[i]!=2) arr[i] = 1-arr[i];
    }
    for(int i = 1; i<=n; ++i){
        if(s2[i-1]=='?') brr[i] = 2;
        else brr[i] = s2[i-1]-'0';
        if((i&1) && brr[i]!=2) brr[i] = 1-brr[i];
    }
    for(int i = 0; i<=n; ++i)
        for(int j = 0; j<=n; ++j)
            for(int x = 0; x<2; ++x)
                for(int y = 0; y<2; ++y)
                    cnt[i][j][x][y] = dp[i][j][x][y] = 0;
    cnt[0][0][0][0] = 1;
    for(int i = 1; i<=n && arr[i]!=1; ++i)
        cnt[i][0][0][0] = 1;
    for(int i = 1; i<=n && brr[i]!=1; ++i)
        cnt[0][i][0][0] = 1;
    for(int i = 1; i<=n; ++i)
        for(int j = 1; j<=n; ++j){
            if(arr[i]!=1 && brr[j]!=1){
                dp[i][j][0][0] = add(add(dp[i-1][j-1][0][0], dp[i-1][j-1][0][1]), add(dp[i-1][j-1][1][0], dp[i-1][j-1][1][1]));
                cnt[i][j][0][0] = add(add(cnt[i-1][j-1][0][0], cnt[i-1][j-1][0][1]), add(cnt[i-1][j-1][1][0], cnt[i-1][j-1][1][1]));
            }
            if(arr[i]!=1 && brr[j]!=0){
                dp[i][j][0][1] = add(dp[i-1][j][0][1], dp[i-1][j][1][1]);
                cnt[i][j][0][1] = add(cnt[i-1][j][0][1], cnt[i-1][j][1][1]);
            }
            if(arr[i]!=0 && brr[j]!=1){
                dp[i][j][1][0] = add(dp[i][j-1][1][0], dp[i][j-1][1][1]);
                cnt[i][j][1][0] = add(cnt[i][j-1][1][0], cnt[i][j-1][1][1]);
            }
            if(arr[i]!=0 && brr[j]!=0){
                dp[i][j][1][1] = add(add(dp[i-1][j-1][0][0], dp[i-1][j-1][0][1]), add(dp[i-1][j-1][1][0], dp[i-1][j-1][1][1]));
                cnt[i][j][1][1] = add(add(cnt[i-1][j-1][0][0], cnt[i-1][j-1][0][1]), add(cnt[i-1][j-1][1][0], cnt[i-1][j-1][1][1]));
                inc(dp[i][j][1][1], mul(abs(i-j), cnt[i][j][1][1]));
            }
        }
    cout << add(add(dp[n][n][0][0], dp[n][n][0][1]), add(dp[n][n][1][0], dp[n][n][1][1])) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}