#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,a[N+5],b[N+5],ans;
vector<pair<int,int>> v;
inline bool check(int p)
{
    int s=(1<<(p+1))-1;
    for(int i=1;i<=n;++i) a[i]&=s,b[i]&=s;
    for(pair<int,int> x:v)
    {
        int l=x.first,r=x.second;
        sort(a+l,a+r+1);
        sort(b+l,b+r+1,greater<int>());
        for(int i=l;i<=r;++i)
            if((a[i]>>p&1)==(b[i]>>p&1)) return 0;
    }
    return 1;
}
inline void change(int p)
{
    vector<pair<int,int>> nxt;
    for(pair<int,int> x:v)
    {
        int l=x.first,r=x.second,i=l;
        while(i<=r && !(a[i]>>p&1)) ++i;
        if(l<i) nxt.push_back({l,i-1});
        if(i<=r) nxt.push_back({i,r});
    }
    v=nxt;
}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),ans=0,v={{1,n}};
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=1;i<=n;++i) scanf("%d",b+i);
        for(int i=29;~i;--i) if(check(i)) change(i),ans|=1<<i;
        printf("%d\n",ans);
    }
    return 0;
}