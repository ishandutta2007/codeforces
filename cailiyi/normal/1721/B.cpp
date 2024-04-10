#include<bits/stdc++.h>
#define N 1000
using namespace std;
int T,n,m,sx,sy,d;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d %d %d %d",&n,&m,&sx,&sy,&d);
        printf("%d\n",(sx+d>=n || sy-d<=1) && (sx-d<=1 || sy+d>=m)?-1:n+m-2);
    }
    return 0;
}