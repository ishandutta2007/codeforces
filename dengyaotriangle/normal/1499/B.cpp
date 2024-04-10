#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=105;

bool dp[maxn][4];
char s[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>(s+1);
        int n=strlen(s+1);
        dp[0][0]=dp[0][2]=1;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                dp[i][0]=dp[i-1][0]|dp[i-1][1];
                dp[i][1]=0;
                dp[i][2]=dp[i][0];
                dp[i][3]=dp[i-1][2];
            }else{
                dp[i][0]=0;
                dp[i][1]=dp[i-1][0];
                dp[i][2]=dp[i-1][2]|dp[i-1][3];
                dp[i][3]=dp[i][1];
            }
        }
        cout<<(accumulate(dp[n],dp[n]+4,0)?"YES\n":"NO\n");
    }
    return 0;
}