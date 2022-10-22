#include<bits/stdc++.h>
#define N 800
using namespace std;
int n,a[N+5],b[N+5],pos[N+5];
inline int query(const vector<int> &v)
{
    printf("? %d ",(int)v.size());
    for(int x:v) printf("%d ",x);
    cout<<endl;int ret=0;cin>>ret;return ret;
}
int ask(int x)
{
    vector<int> v;
    for(int i=1;i<=n;++i) if(!a[i] && i!=x) v.push_back(i);
    return query(v);
}
inline void solve(int x,int y,int p,int q)
{
    for(int i=1;i<=n;++i)
        if(!pos[x] && !a[i] && b[i]==p && ask(i)) pos[x]=i;
        else if(!pos[y] && !a[i] && b[i]==q && ask(i)) pos[y]=i;
    a[pos[x]]=x,a[pos[y]]=y;
}
int main()
{
    scanf("%d",&n),solve(1,n,0,0);
    for(int l=2,r=n-1,t=2;l<=r;t<<=1)
    {
        for(int i=1;i<=n;++i) if(!a[i])
        {
            vector<int> v;v.push_back(i);
            for(int j=1;j<=t;++j) if(j%t!=b[i]%t) v.push_back(pos[j]);
            if(query(v)) b[i]+=t>>1;
        }
        while(l<=r && l<=t<<1) solve(l,r,l%t,r%t),++l,--r;
    }
    if(a[1]>n/2) for(int i=1;i<=n;++i) a[i]=n+1-a[i];
    printf("! ");
    for(int i=1;i<=n;++i) printf("%d%c",a[i]," \n"[i==n]);
    fflush(stdout);
    return 0;
}