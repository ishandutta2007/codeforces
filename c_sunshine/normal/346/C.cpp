#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,p[100005],a,b,pre[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",p+i);
    scanf("%d%d",&b,&a);
    for(int i=a;i<=b;i++)
        pre[i+1-a]=i;
    sort(p+1,p+n+1);
    int m=0;
    for(int i=1,t,j;i<=n;i++)
        if(m==0||p[i]!=p[m])
        {
            p[++m]=t=p[i];
            j=b-b%t;
            if(j>=a)
            {
                pre[b-a]=min(pre[b-a],j);
                for(j-=t;j>=a;j-=t)
                    pre[j+t-1-a]=min(pre[j+t-1-a],j);
            }
        }
    for(int i=b;i>=a;i--)
        pre[i-a]=min(pre[i+1-a],pre[i-a]);
    int ans=0;
    for(int k=b;k!=a;k=pre[k-a])ans++;
    printf("%d\n",ans);
    return 0;
}