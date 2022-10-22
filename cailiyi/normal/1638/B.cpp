#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,a[N+5],last[2];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n),last[0]=last[1]=0;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(last[a[i]&1]>a[i])
            {
                flag=0;break;
            }
            last[a[i]&1]=a[i];
        }
        puts(flag?"Yes":"No");
    }
    return 0;
}