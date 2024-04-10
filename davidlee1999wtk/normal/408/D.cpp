#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
LL sum=0,dp[1005],p=1000000007;
int b[1005];
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    dp[1]=0; sum=1;
    for(i=2;i<=n;i++)
    {
        sum++;
        dp[i]=sum%p;
        sum+=dp[i]-dp[b[i]]+1;
        sum=(sum+p)%p;
    }
    sum=(sum+1)%p;
    cout<<sum<<endl;
    return 0;
}
// davidlee1999WTK 2014/