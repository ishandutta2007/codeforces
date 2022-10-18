#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;
const long long mdn=1000000007;

char s[maxn];
int n;
long long dp[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>(s+1);    
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='m'||s[i]=='w'){
            cout<<0;
            return 0;
        }
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(s[i]=='u'&&s[i-1]=='u'){
            dp[i]+=dp[i-2];
        }
        if(s[i]=='n'&&s[i-1]=='n'){
            dp[i]+=dp[i-2];
        }
        dp[i]%=mdn;
    }
    cout<<dp[n];
    return 0;
}