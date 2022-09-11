#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 3010
long long dp[SIZE],sum[SIZE];
struct data{
    int x,c;
    bool operator<(data b)const{return x<b.x;}
}a[SIZE];
main(){
    int i,j,n;
    long long an=-1000000000000000000ll;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].c);
    sort(a,a+n);
    dp[0]=a[0].c;
    for(i=1;i<n;i++)sum[i]=sum[i-1]+a[i].x;
    for(i=1;i<n;i++){
        dp[i]=-1000000000000000000ll;
        for(j=0;j<i;j++){
            if(dp[i]==-1000000000000000000ll||dp[i]>a[i].c+dp[j]+sum[i-1]-sum[j]-(long long)a[j].x*(i-1-j)){
                dp[i]=a[i].c+dp[j]+sum[i-1]-sum[j]-(long long)a[j].x*(i-1-j);
            }
        }
    }
    for(i=0;i<n;i++){
        if(an==-1000000000000000000ll||an>dp[i]+sum[n-1]-sum[i]-(long long)a[i].x*(n-1-i)){
            an=dp[i]+sum[n-1]-sum[i]-(long long)a[i].x*(n-1-i);
        }
    }
    cout<<an<<endl;
}