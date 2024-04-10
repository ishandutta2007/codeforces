#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int n, m;
char s[1005], t[1005];
ll fs[1005], ft[1005];

ll DP[1005][1005][2]; /// 0: , 1: 
ll ans;

int main(){
    scanf("%s %s", s+1, t+1);
    n = strlen(s+1);
    m = strlen(t+1);

    for(int i=1; i<=n; i++){
        fs[i] = 1;
        for(int j=i+1; j<=n; j++){
            if(s[j] == s[j-1]) break;
            fs[i]++;
        }
    }
    for(int i=1; i<=m; i++){
        ft[i] = 1;
        for(int j=i+1; j<=m; j++){
            if(t[j] == t[j-1]) break;
            ft[i]++;
        }
    }

    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            ///  0 .
            if(s[i] != t[j]) DP[i][j][0] = ft[j];
            if(s[i] != s[i+1]) DP[i][j][0] += DP[i+1][j][0];
            if(s[i] != t[j]) DP[i][j][0] += DP[i+1][j][1];
            DP[i][j][0] %= MOD;

            ///  1 .
            if(s[i] != t[j]) DP[i][j][1] = fs[i];
            if(t[j] != t[j+1]) DP[i][j][1] += DP[i][j+1][1];
            if(s[i] != t[j]) DP[i][j][1] += DP[i][j+1][0];
            DP[i][j][1] %= MOD;

//            printf("%d %d: %lld %lld\n", i, j, DP[i][j][0], DP[i][j][1]);

            ans += DP[i][j][0] + DP[i][j][1];
            ans %= MOD;
        }
    }
    printf("%lld", ans);
}