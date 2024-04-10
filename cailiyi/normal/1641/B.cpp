#include<bits/stdc++.h>
#define N 500
using namespace std;
int T,n,a[N+5],b[N+5],c[N+5];
inline bool check()
{
    int cnt1=0,cnt2=n>>1;
    for(int i=1,last=-1,num=0;i<=n+1;++i,++num)
        if(last!=b[i])
        {
            if(num&1) return 1;
            for(;num;num-=2)
                c[++cnt1]=c[++cnt2]=last;
            last=b[i];
        }
    return 0;
}
vector<int> v;
vector<pair<int,int> > opt;
inline void Reverse(int x)
{
    reverse(a+x,a+n+1);
    for(int i=x;i<=n;++i)
        opt.push_back({i-1,a[i]});
    v.push_back((n-x+1)<<1);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",a+i),b[i]=a[i];
        sort(b+1,b+1+n),b[n+1]=0;
        if(check()) {puts("-1");continue;}
        v.clear(),opt.clear();
        for(int i=1;i<=n;++i)
            if(a[i]!=c[i])
                for(int j=n;j>i;--j)
                    if(a[j]==c[i])
                    {
                        Reverse(j);
                        Reverse(i);
                        break;
                    }
        printf("%d\n",(int)opt.size());
        for(pair<int,int> x:opt)
            printf("%d %d\n",x.first,x.second);
        printf("%d\n",(int)v.size()+1);
        printf("%d ",n);
        for(int i=v.size()-1;i>=0;--i)
            printf("%d ",v[i]);
        putchar('\n');
    }
    return 0;
}