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
int a[5],b[5];
int main()
{
    int i,j,f1,f2;
    scanf("%d%d%d%d",&a[1],&b[2],&a[2],&b[1]);
    scanf("%d%d%d%d",&a[3],&b[4],&a[4],&b[3]);
    f1=-1;
    for(i=1;i<=2;i++)
    {
        f2=-1;
        for(j=1;j<=2;j++)
        {
            if(a[i]<b[j+2]&&b[i]<a[j+2])
                f2=1;
            else if(!(a[i]>b[j+2]&&b[i]>a[j+2]))
                f2=max(f2,0);
        }
        f1=max(f1,0-f2);
    }
    if(f1==-1)
        printf("Team 2\n");
    else if(f1==0)
        printf("Draw\n");
    else printf("Team 1\n");
    return 0;
}
// davidlee1999WTK 2014/
//ios::sync_with_stdio(false);