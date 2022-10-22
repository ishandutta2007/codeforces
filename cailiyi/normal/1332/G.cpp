#include<bits/stdc++.h>
#define N 200000
using namespace std;
int n,q,a[N+5],le3[N+5],ri4[N+5],g[N+5],l,r;
int st1[N+5],top1,st2[N+5],top2;
vector<int> v[N+5];
set<int> s;
namespace st
{
    int log_2[N+5];
    pair<int,int> f1[N+5][18],f2[N+5][18];
    inline void init()
    {
        log_2[0]=-1;for(int i=1;i<=n;++i)
        {
            log_2[i]=log_2[i>>1]+1,f1[i][0]=f2[i][0]={a[i],i};
            for(int j=1;1<<j<=i;++j)
            {
                f1[i][j]=max(f1[i][j-1],f1[i-(1<<(j-1))][j-1]);
                f2[i][j]=min(f2[i][j-1],f2[i-(1<<(j-1))][j-1]);
            }
        }
    }
    inline pair<int,int> query(int l,int r)
    {
        int p=log_2[r-l+1];
        return {max(f1[r][p],f1[l+(1<<p)-1][p]).second,
            min(f2[r][p],f2[l+(1<<p)-1][p]).second};
    }
}
using namespace st;
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1,down=1,up=1;i<=n;++i)
    {
        scanf("%d",a+i);
        if(a[i]<a[i-1]) up=i;
        if(a[i]>a[i-1]) down=i;
        le3[i]=min(up,down);
    }
    for(int i=1;i<=n;++i)
    {
        while(top1 && a[i]>=a[st1[top1]]) --top1;
        while(top2 && a[i]<=a[st2[top2]]) --top2;
        v[min(st1[top1],st2[top2])].emplace_back(i);
        st1[++top1]=st2[++top2]=i;
    }
    st1[top1=0]=st2[top2=0]=n+1;
    s.insert(ri4[g[n+1]=n+1]=n+2);
    for(int i=n;i;--i)
    {
        while(top1 && a[i]>=a[st1[top1]]) --top1;
        while(top2 && a[i]<=a[st2[top2]]) --top2;
        ri4[i]=*s.upper_bound(max(st1[top1],st2[top2]));
        g[i]=ri4[g[i+1]]<ri4[i]?g[i+1]:i;
        st1[++top1]=st2[++top2]=i;
        for(int x:v[i]) s.insert(x);
    }
    init();
    while(q--)
    {
        scanf("%d %d",&l,&r);
        if(ri4[g[l]]<=r)
        {
            pair<int,int> temp=query(g[l],ri4[g[l]]);
            printf("4\n%d %d %d %d\n",g[l],min(temp.first,temp.second),
            max(temp.first,temp.second),ri4[g[l]]);
        }
        else if(le3[r]>l) printf("3\n%d %d %d\n",le3[r]-1,le3[r],r);
        else puts("0");
    }
    return 0;
}