#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 5010
int a[SIZE],b[SIZE];
long long dp[SIZE];
main(){
    int n,i,j;
    long long tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b,b+n);
    for(i=0;i<n;i++){
        dp[i]=abs(b[i]-a[0]);
        if(i)dp[i]=min(dp[i],dp[i-1]);
    }
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            dp[j]+=abs(b[j]-a[i]);
            if(j)dp[j]=min(dp[j],tmp);
            tmp=dp[j];
        }
    }
    printf("%I64d\n",dp[n-1]);
}