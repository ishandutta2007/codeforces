#include<stdio.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 4040
struct data{
    int x,y;
}a[SIZE];
int dp[SIZE][SIZE];
int main(){
    int i,j,k,n,an=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    if(k==n){
        printf("86400\n");
        return 0;
    }
    an=a[1].x-1;
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            dp[i][j]=min(dp[i-1][j],max(dp[i-1][j-1],a[i].x-1)+a[i].y);
        }
        dp[i][i]=max(dp[i-1][j-1],a[i].x-1)+a[i].y;
        if(i>1)an=max(an,a[i].x-dp[i-1][max(i-1-k,0)]-1);
    }
    an=max(an,86400-dp[n][n-k]);
    cout<<an<<endl;
    return 0;
}