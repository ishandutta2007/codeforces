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
int k[105],sum[105];
int main()
{
    int i,j,n,it;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&k[i]);
    for(i=1;i<=n;i++)
    {
        sum[i]=k[i]*15;
        for(j=1;j<=k[i];j++)
        {
            scanf("%d",&it);
            sum[i]+=it*5;
        }
    }
    sort(sum+1,sum+1+n);
    printf("%d",sum[1]);
    return 0;
}
// davidlee1999WTK 2014/