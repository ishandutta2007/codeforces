#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 1e9+7;
int dp[2][maxn][26];
int C[maxn][maxn];
char s[maxn];
int n;
void init(){
    C[0][0] = 1;
    for (int i=1;i<=5001;i++){
        C[i][0] = C[i][i] = 1;
        for (int j=1;j<i;j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) %mod;
        }
    }
}
inline void add(int &tar, int delta){
    (tar += delta) %= mod;
}
int main(){
    init();
    scanf("%d",&n);
    scanf("%s",s);
    dp[0][1][s[0] - 'a'] = 1;
    int now = 0;
    for (int i=1;i<n;i++,now ^= 1){
       // cerr<<i<<":"<<endl;
        //memset(dp[now^1],0,sizeof dp[now^1]);
        int nowch = s[i] - 'a';
        for (int j=2;j<=i+1;j++){
            dp[now^1][j][nowch] = 0;
        }
        for (int ch = 0;ch < 26;ch ++){
            dp[now^1][1][ch] = dp[now][1][ch];
        }
        dp[now^1][1][nowch] = 1;
        for (int j=2;j<=i+1;j++){
            for (int prech = 0;prech<26;prech++) {
                if (prech != nowch) {
                    add(dp[now ^ 1][j][nowch], dp[now][j - 1][prech]);
                    dp[now ^ 1][j][prech] = dp[now][j][prech];
                }
                // else add(dp[now^1][j][s[i] - 'a'],-dp[now][j][s[i] - 'a']);
            }
        }
      //  for (int j=1;j<=n;j++)for (int ch = 0;ch < 26;ch ++)if (dp[now^1][j][ch])cerr<<"dp["<<i<<"]["<<j<<"]["<<ch<<"]="<<dp[now^1][j][ch]<<endl;
    }
    int ans =0;
    for (int i=1;i<= n;i++){
        int temp_ans = 0;
        for (int ch =0;ch < 26;ch ++)add(temp_ans,dp[now][i][ch]);
        add(ans,1ll * temp_ans * C[n-1][i-1] % mod);
      //  cerr<<i<<" "<<temp_ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}