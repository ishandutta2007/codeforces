#include <bits/stdc++.h>
using namespace std;
#define MAXN 55
#define MOD 1000000007

inline int add(int a, int b){return (a+b >= MOD)?a+b-MOD: a+b;}
inline void inc(int &a, int b){a = add(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}

int dp[MAXN][MAXN][2] = {{0}}; // 0: gone, 1: not gone
int comb[MAXN][MAXN] = {{0}};
const int inv2 = 500000004;
int n, k;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if(k > n/2){
        cout << 0 << endl;
        exit(0);
    }
    for(int i = 1; i<MAXN; i++){
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j<i; j++) comb[i][j] = add(comb[i-1][j], comb[i-1][j-1]);
    }
    dp[0][0][0] = 1;
    dp[1][0][1] = 1;
    for(int i = 2; i<=n; i++){
        for(int j = 0; j<=i/2; j++){
            int tmp1 = 0;
            for(int a = 0; a<=i-1; a++){
                for(int b = 0; b<=min(a/2, j); b++){
                    inc(tmp1, mul(mul(mul(dp[a][b][0], dp[i-1-a][j-b][0]), comb[i-1][a]),max(a,1)*max(1,(i-1-a))));
                }
            }
            tmp1 = mul(tmp1, inv2);
            int tmp0 = 0;
            for(int a = 0; a<=i-1; a++){
                for(int b = 0; b<=min(a/2, j-1); b++){
                    int t2 = add(add(mul(dp[a][b][0], dp[i-1-a][j-1-b][1]),mul(dp[a][b][1], dp[i-1-a][j-1-b][0])), mul(dp[a][b][1],dp[i-1-a][j-1-b][1]));
                    t2 = mul(t2, comb[i-1][a]);
                    t2 = mul(t2, max(a,1)*max(1,(i-1-a)));
                    inc(tmp0, t2);
                }
            }
            tmp0 = mul(tmp0, inv2);
            dp[i][j][1] = tmp1;
            dp[i][j][0] = tmp0;
        }
    }
    cout << add(dp[n][k][0],dp[n][k][1]) << endl;
}