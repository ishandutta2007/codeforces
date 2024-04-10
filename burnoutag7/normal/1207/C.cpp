#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n,a,b;
string s;
ll dp[200005][3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        cin>>s;
        s+='0';
        dp[0][1]=b;
        dp[0][2]=1e18;
        for(int i=1;i<=n;i++){
            dp[i][1]=1e18;
            dp[i][2]=1e18;
            if(s[i-1]=='0'&&s[i]=='0'){
                dp[i][1]=min(dp[i-1][1]+a+b,dp[i-1][2]+a+a+b);
            }
            dp[i][2]=min(dp[i-1][2]+a+b+b,dp[i-1][1]+a+a+b+b);
        }
        cout<<dp[n][1]<<endl;
    }

    return 0;
}