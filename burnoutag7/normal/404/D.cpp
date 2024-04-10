#include<bits/stdc++.h>
using namespace std;

void inline mod(int & a){
    if(a>=1000000007)a-=1000000007;
}

char s[1000006];
int n,ans;
int dp[1000006][5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    if(s[1]=='?'){
        dp[1][0]=dp[1][1]=dp[1][4]=1;
    }else
    if(s[1]=='0'){
        dp[1][0]=1;
    }else
    if(s[1]=='1'){
        dp[1][1]=1;
    }else
    if(s[1]=='2'){
        
    }else
    if(s[1]=='*'){
        dp[1][4]=1;
    }
    for(int i=2;i<=n;i++){
        if(s[i]=='?'){
            dp[i][0]=dp[i-1][0]+dp[i-1][2];mod(dp[i][0]);
            dp[i][1]=dp[i-1][0]+dp[i-1][2];mod(dp[i][1]);
            dp[i][2]=dp[i-1][4];mod(dp[i][2]);
            dp[i][3]=dp[i-1][4];mod(dp[i][3]);
            dp[i][4]=dp[i-1][1]+dp[i-1][3];mod(dp[i][4]);
            dp[i][4]+=dp[i-1][4];mod(dp[i][4]);
        }
        if(s[i]=='0'){
            dp[i][0]=dp[i-1][0]+dp[i-1][2];mod(dp[i][0]);
        }
        if(s[i]=='1'){
            dp[i][1]=dp[i-1][0]+dp[i-1][2];mod(dp[i][1]);
            dp[i][2]=dp[i-1][4];mod(dp[i][2]);
        }
        if(s[i]=='2'){
            dp[i][3]=dp[i-1][4];mod(dp[i][3]);
        }
        if(s[i]=='*'){
            dp[i][4]=dp[i-1][1]+dp[i-1][3];mod(dp[i][4]);
            dp[i][4]+=dp[i-1][4];mod(dp[i][4]);
        }
    }
    ans+=dp[n][0];mod(ans);
    ans+=dp[n][2];mod(ans);
    ans+=dp[n][4];mod(ans);
    cout<<ans<<endl;

    return 0;
}