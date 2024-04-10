#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e6+3;

int n,m,a[2005];
ll dp[2005][2005];
char s[2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    if(!isdigit(s[n])){
        cout<<"0\n";
        return 0;
    }
    int prv=0;
    for(int i=1;i<=n;i++){
        if(!isdigit(s[i])){
            if(prv){
                a[++m]=1;
                prv=0;
            }else if(s[i]!='*'&&s[i]!='/')++m;
            else{
                cout<<"0\n";
                return 0;
            }
        }else prv=1;
    }
    dp[m+1][m]=1;
    for(int i=m;i>=1;i--){
        dp[i][i]=dp[i][i-1]=1;
        for(int j=i+1;j<=m;j++){
            dp[i][j]+=dp[i+1-a[i]][j];
            for(int k=i;k<=j;k++){
                if(a[k])dp[i][j]+=dp[i][k-1]*dp[k+1][j];
            }
            dp[i][j]%=mod;
        }
    }
    cout<<dp[1][m]<<endl;

    return 0;
}