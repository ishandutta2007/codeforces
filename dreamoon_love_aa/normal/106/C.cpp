#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1000000000
int dp[1001];
main(){
    int n,m,a,b,c,d,an,i,j,k;
    scanf("%d%d%d%d",&n,&m,&c,&d);
    for(i=1;i<=n;i++)dp[i]=-1;
    for(i=c;i<=n;i+=c)dp[i]=dp[i-c]+d;
    for(i=0;i<m;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a/=b;
        while(a--){
            for(j=n-c;j>=0;j--)
                if(dp[j]>=0&&dp[j]+d>dp[j+c])dp[j+c]=dp[j]+d;
        }
    }
    an=0;
    for(i=0;i<=n;i++)an=max(an,dp[i]);
    printf("%d\n",an);
}