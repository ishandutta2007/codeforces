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
char mx[12][12];
int ok[10];
int main()
{
    int t,i,j,ans;
    int  c[15];
    char a[15];
    cin>>t;
    while(t--)
    {
        ans=0;
        memset(ok,0,sizeof(ok));
        scanf("%s",a);
        for(i=1;i<=12;i++)
            c[i]=a[i-1]=='X'?1:0;
        for(i=1;i<=12;i++)
            if(!c[i])
                break;
        if(i==13)
        {
            ans++;
            ok[6]=1;
        }
        for(i=1;i<=12;i++)
            if(c[i])
            {
                ans++;
                ok[1]=1;
                break;
            }

        for(i=1;i<=12;i++)
            mx[(i-1)/6][(i-1)%6]=c[i];
        for(j=0;j<=5;j++)
            if(mx[0][j]&&mx[1][j])
            {
                ans++;
                ok[2]=1;
                break;
            }
        for(i=1;i<=12;i++)
            mx[(i-1)/4][(i-1)%4]=c[i];
        for(j=0;j<=3;j++)
            if(mx[0][j]&&mx[1][j]&&mx[2][j])
            {
                ans++;
                ok[3]=1;
                break;
            }
        for(i=1;i<=12;i++)
            mx[(i-1)/3][(i-1)%3]=c[i];
        for(j=0;j<=2;j++)
            if(mx[0][j]&&mx[1][j]&&mx[2][j]&&mx[3][j])
            {
                ans++;
                ok[4]=1;
                break;
            }
        for(i=1;i<=12;i++)
            mx[(i-1)/2][(i-1)%2]=c[i];
        for(j=0;j<=1;j++)
            if(mx[0][j]&&mx[1][j]&&mx[2][j]&&mx[3][j]&&mx[4][j]&&mx[5][j])
            {
                ans++;
                ok[5]=1;
                break;
            }
        printf("%d",ans);
        if(ok[1]) printf(" 1x12");
        if(ok[2]) printf(" 2x6");
        if(ok[3]) printf(" 3x4");
        if(ok[4]) printf(" 4x3");
        if(ok[5]) printf(" 6x2");
        if(ok[6]) printf(" 12x1");
        printf("\n");
    }
    return 0;
}
// davidlee1999WTK 2014/3/5