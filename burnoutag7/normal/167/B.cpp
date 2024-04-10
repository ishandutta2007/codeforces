#include<bits/stdc++.h>
using namespace std;
 
int n,l,K;
int p[205];
int a[205];
double dp[205][205][405],ans;
 
int main(){
 
    cin>>n>>l>>K;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][0][K+200]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=400;k++){
                if(j!=0){
                    dp[i][j][min(k+a[i],400)]+=dp[i-1][j-1][k]*p[i]/100;
                }
                dp[i][j][k]+=dp[i-1][j][k]*(100-p[i])/100;
            }
        }
    }
    ans=0;
    for(int i=l;i<=n;i++){
        for(int j=200;j<=400;j++){
            ans+=dp[n][i][j];
        }
    }
    printf("%.7lf\n",ans);
 
    return 0;
}