#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 500
using namespace std;
int T,n,k;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        if(k==1)
        {
            puts("YES");
            for(int i=1;i<=n;++i)
                printf("%d\n",i);
        }
        else if(n&1) puts("NO");
        else
        {
            puts("YES");
            for(int i=1,now=1;i<=n>>1;++i)
                for(int j=1;j<=k;++j,now+=2)
                    printf("%d%c",now," \n"[j==k]);
            for(int i=1,now=2;i<=n>>1;++i)
                for(int j=1;j<=k;++j,now+=2)
                    printf("%d%c",now," \n"[j==k]);
        }
    }
    return 0;
}