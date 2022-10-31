#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, dp[N][N], ans;
array<int, 2> events[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        char c; cin >> c;
        if(c == '+'){
            int a; cin >> a;
            events[i] = {1, a};
        } else events[i] = {0, 0};
    }
    for(int i = 1; i<=n; i++){
        if(events[i][0] == 0) continue;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int j = 1; j<i; j++){
            for(int k = 0; k<=j; k++)
                dp[j][k] = dp[j-1][k];
            if(events[j][0] == 0){
                for(int k = 0; k<=j; k++)
                    inc(dp[j][k], dp[j-1][k+1]);
                inc(dp[j][0], dp[j-1][0]);
            } else{
                if(events[j][1] <= events[i][1])
                    for(int k = 1; k<=j; k++)
                        inc(dp[j][k], dp[j-1][k-1]);
                else for(int k = 0; k<=j; k++)
                         inc(dp[j][k], dp[j-1][k]);
            }
        }
        for(int j = 1; j<=i; j++)
            dp[i][j] = dp[i-1][j-1];
        for(int j = i+1; j<=n; j++){
            for(int k = 1; k<=j; k++)
                dp[j][k] = dp[j-1][k];
            if(events[j][0] == 0){
                for(int k = 1; k<=j; k++)
                    inc(dp[j][k], dp[j-1][k+1]);
            } else{
                if(events[j][1] < events[i][1])
                    for(int k = 2; k<=j; k++)
                        inc(dp[j][k], dp[j-1][k-1]);
                else for(int k = 1; k<=j; k++)
                         inc(dp[j][k], dp[j-1][k]);
            }
        }
        int tmp = 0;
        for(int j = 1; j<=n; j++)
            inc(tmp, dp[n][j]);
        inc(ans, mul(tmp, events[i][1]));
    }
    cout << ans << endl;
}