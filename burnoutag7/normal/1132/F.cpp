#include<bits/stdc++.h>
using namespace std;

int n;
char s[505];
int dp[505][505][26],mn[505][505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    {
        int N;
        cin>>N;
        char c;
        while(N--){
            cin>>c;
            if(c!=s[n])s[++n]=c;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    memset(mn,0x3f,sizeof(mn));
    for(int i=0;i<=n;i++)mn[i+1][i]=0;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){
                dp[i][j][s[k]-'a']=min(dp[i][j][s[k]-'a'],mn[i][k-1]+mn[k+1][j]+1);
                dp[i][j][s[k]-'a']=min(dp[i][j][s[k]-'a'],dp[i][k-1][s[k]-'a']+dp[k+1][j][s[k]-'a']-1);
                dp[i][j][s[k]-'a']=min(dp[i][j][s[k]-'a'],dp[i][k-1][s[k]-'a']+mn[k+1][j]);
                dp[i][j][s[k]-'a']=min(dp[i][j][s[k]-'a'],mn[i][k-1]+dp[k+1][j][s[k]-'a']);
            }
            mn[i][j]=*min_element(dp[i][j],dp[i][j]+26);
        }
    }
    cout<<mn[1][n]<<endl;

    return 0;
}