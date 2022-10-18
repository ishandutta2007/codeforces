#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;

int n;
long long a[maxn];
long long dp[maxn][4];
int bk[maxn][4];
int cl[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(dp,0xc0,sizeof(dp));
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            long long mx=0xc000c000c000c000;
            for(int k=0;k<=j;k++){
                if(dp[i-1][k]>mx){
                    mx=dp[i-1][k];
                    bk[i][j]=k;
                }
            }
            if(j==0||j==2) dp[i][j]=mx+a[i];
            else dp[i][j]=mx-a[i];
        }
    }
    long long mx=0xc000c000c000c000;
    int id;
    for(int k=0;k<4;k++){
        if(dp[n][k]>mx){
            mx=dp[n][k];
            id=k;
        }
    }
    cl[n]=id;
    for(int i=n-1;i>=1;i--){
        cl[i]=bk[i+1][cl[i+1]];
    }
    int cur=0;
    cl[n+1]=3;
    for(int i=1;i<=n+1;i++){
        while(cur<cl[i]){
            cout<<i-1<<' ';
            cur++;
        }
    }
    return 0;
}