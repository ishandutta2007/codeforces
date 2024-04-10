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
int x[100005],y[100005],tx,ty;
int main()
{
    int n,m,xx,zz,yy,p,i;
    cin>>n>>m>>xx>>yy>>zz>>p;
    xx%=4;
    yy%=2;
    zz%=4;
    for(i=1;i<=p;i++)
        scanf("%d%d",&x[i],&y[i]);
    while(xx--)
    {
        for(i=1;i<=p;i++)
        {
            tx=x[i]; ty=y[i];
            y[i]=n+1-tx;
            x[i]=ty;
        }
        swap(n,m);
    }
    while(yy--)
    {
        for(i=1;i<=p;i++)
        {
            tx=x[i]; ty=y[i];
            y[i]=m+1-ty;
        }
    }
    zz=4-zz;
    while(zz--)
    {
        for(i=1;i<=p;i++)
        {
            tx=x[i]; ty=y[i];
            y[i]=n+1-tx;
            x[i]=ty;
        }
        swap(n,m);
    }
    for(i=1;i<=p;i++)
        printf("%d %d\n",x[i],y[i]);
    return 0;
}
// davidlee1999WTK 2014/