#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,m,u[N+5],v[N+5],p[N+5],fa[N+5];
char ans[N+5];
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool work()
{
    vector<int> vec;
    for(int i=1;i<=m;++i) ans[i]='0';
    random_shuffle(p+1,p+1+m),iota(fa+1,fa+1+n,1);
    for(int i=1;i<=m;++i)
    {
        int x=u[p[i]],y=v[p[i]];
        if(find(x)==find(y)) ans[p[i]]='1',vec.push_back(x),vec.push_back(y);
        else fa[fa[y]]=fa[x];
    }
    sort(vec.begin(),vec.end());
    return m==n+2 && (int)(unique(vec.begin(),vec.end())-vec.begin())==3;
}
int main()
{
    srand(time(0));
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m),ans[m+1]=0;
        for(int i=1;i<=m;++i)
            scanf("%d %d",u+i,v+i),p[i]=i;
        while(work());
        puts(ans+1);
    }
}