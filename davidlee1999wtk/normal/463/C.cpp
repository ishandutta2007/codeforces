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
#define K 2000
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[2005][2005];
LL sumz[4005],sumf[4005];
int main()
{
    int n,i,j,x1,x2,y1,y2;
    LL maxw=-1,maxb=-1;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            sumz[i+j]+=a[i][j];
            sumf[i-j+K]+=a[i][j];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if((i+j)%2==0)
            {
                if(maxw<sumz[i+j]+sumf[i-j+K]-a[i][j])
                {
                    maxw=sumz[i+j]+sumf[i-j+K]-a[i][j];
                    x1=i,y1=j;
                }
            }
            else
            {
                if(maxb<sumz[i+j]+sumf[i-j+K]-a[i][j])
                {
                    maxb=sumz[i+j]+sumf[i-j+K]-a[i][j];
                    x2=i,y2=j;
                }
            }
        }
    cout<<maxw+maxb<<endl;
    printf("%d %d %d %d\n",x1,y1,x2,y2);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);