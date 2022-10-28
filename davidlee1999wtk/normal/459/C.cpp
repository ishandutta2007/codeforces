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
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int p[1005];
int main()
{
    int t,n,k,d,cf=1,flag=0,i;
    cin>>n>>k>>d;
    for(t=1;t<=d;t++)
    {
        cf*=k;
        if(cf>=n) flag=1;
    }
    if(!flag)
    {
        printf("-1");
        return 0;
    }
    for(i=1;i<=n;i++)
        p[i]=(i-1)%k+1;
    flag=0,cf=1;
    for(t=1;t<=d;t++)
    {
        if(flag==0)
            for(i=1;i<=n;i++)
            {
                printf("%d ",p[i]);
                p[i]=(((i-1)/k/cf)%k-1+p[i])%k+1;
            }
        else
            for(i=1;i<=n;i++)
                printf("1 ");
        printf("\n");
        cf*=k;
        if(cf>=n) flag=1;
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);