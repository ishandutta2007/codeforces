#include<bits/stdc++.h>
using namespace std;

int n,q;
char s[2][200005];
bool dp[2][200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        cin>>s[0]+1;
        cin>>s[1]+1;
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[0][i]=dp[1][i]=false;
            dp[0][i]|=dp[0][i-1]&&(s[0][i]=='1'||s[0][i]=='2');
            dp[1][i]|=dp[1][i-1]&&(s[1][i]=='1'||s[1][i]=='2');
            dp[0][i]|=dp[1][i-1]&&(s[0][i]=='3'||s[0][i]=='4'||s[0][i]=='5'||s[0][i]=='6')&&(s[1][i]=='3'||s[1][i]=='4'||s[1][i]=='5'||s[1][i]=='6');
            dp[1][i]|=dp[0][i-1]&&(s[0][i]=='3'||s[0][i]=='4'||s[0][i]=='5'||s[0][i]=='6')&&(s[1][i]=='3'||s[1][i]=='4'||s[1][i]=='5'||s[1][i]=='6');
        }
        if(dp[1][n]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}