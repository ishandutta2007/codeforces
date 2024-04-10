#include<bits/stdc++.h>
#define N 300000
using namespace std;
int T,n,m,p1,p2,p;
unsigned long long val1,val2;
unsigned long long c[N+5],now;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m),p1=p2=p=0;
        for(int j=1;j<=n;++j)
        {
            unsigned long long sum=0;
            for(int i=1;i<=m;++i)
                scanf("%llu",c+i),c[i]+=c[i-1],sum+=c[i];
            if(p1 && sum==val1) p=2;
            else if(p2 && sum==val2) p=1;
            else if(!p1)  p1=j,val1=sum;
            else p2=j,val2=sum;
        }
        if(p==1) printf("%d %llu\n",p1,val2-val1);
        else printf("%d %llu\n",p2,val1-val2);
    }
    return 0;
}