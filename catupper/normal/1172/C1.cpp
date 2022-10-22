#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n, m;
Int a[55], w[55];
Int dp[55][55][55];

Int mod_pow(Int x, Int a, Int m = MOD){
    if(a == 0)return 1;
    Int res = mod_pow(x, a / 2, m);
    res = res * res % m;
    if(a % 2)res *= x;
    return res % m;
}

Int inv(Int x, Int m = MOD){
    return mod_pow(x, m-2, m);
}


Int solve(Int id){
    Int otherplus = 0;
    Int otherminus = 0;
    Int sm = 0;
    for(int i = 0;i < n;i++){
        sm += w[i];
        if(i == id)continue;
        if(a[i] == 0)otherminus += w[i];
        else otherplus += w[i];
    }
    for(int i = 0;i < 55;i++)
        for(int j = 0;j < 55;j++)
            for(int k = 0;k < 55;k++)
                dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for(Int i = 0;i < m;i++){
        for(int j = 0;j <=i;j++){
            Int plus = j, minus = i - j;
            if(sm + plus - minus <= 0)continue;
            for(int k = 0;k <= i;k++){
                //plus
                dp[i+1][j+1][k] += dp[i][j][k] * (otherplus + plus - ((a[id]==1)?k:0)) % MOD * inv(sm + plus - minus) % MOD;dp[i+1][j+1][k] %= MOD;
                if(a[id] == 1)
                    dp[i+1][j+1][k+1] += dp[i][j][k] * (w[id] + k) % MOD * inv(sm + plus - minus) % MOD;dp[i+1][j+1][k+1] %= MOD;
                //minus
                dp[i+1][j][k] += dp[i][j][k] * (otherminus - minus + ((a[id]==0)?k:0)) % MOD * inv(sm + plus - minus) % MOD;dp[i+1][j][k] %= MOD;
                if(a[id] == 0 && w[id] - k > 0)
                    dp[i+1][j][k+1] += dp[i][j][k] * (w[id] - k) % MOD * inv(sm + plus - minus) % MOD;dp[i+1][j][k+1] %= MOD;
                
            }
        }
    }
    Int res = 0;
    for(int i = 0;i <= m;i++){
        for(int j = 0;j <= m;j++){
            Int noww = w[id] + ((a[id]==0)?-j:j);
            if(noww <= 0)continue;
            res += dp[m][i][j] * noww % MOD;
            res %= MOD;
        }
    }
    return res;
}


int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> w[i];
    for(int i = 0;i < n;i++)cout << solve(i) << endl;
    return 0;
}