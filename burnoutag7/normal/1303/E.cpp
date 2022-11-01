#include<bits/stdc++.h>
using namespace std;

int ss,st,sa,sb;
char s[405],t[405],a[405],b[405];
int dp[405][405];

bool solve(){
    for(int i=0;i<=ss;i++){
        for(int j=0;j<=sa;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<ss;i++){
        for(int j=0;j<=sa;j++){
            if(dp[i][j]==-1)continue;
            if(s[i+1]==a[j+1]){
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
            }
            if(s[i+1]==b[dp[i][j]+1]){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
            }
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
    }
    return dp[ss][sa]>=sb;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>s+1;
        ss=strlen(s+1);
        cin>>t+1;
        st=strlen(t+1);
        bool fl=false;
        for(int i=0;i<=st;i++){
            sa=i;
            sb=st-i;
            memcpy(a+1,t+1,sa);
            memcpy(b+1,t+1+sa,sb);
            if(solve()){
                fl=true;
                break;
            }
        }
        if(fl)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}