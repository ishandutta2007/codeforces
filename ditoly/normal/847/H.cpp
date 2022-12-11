#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],v[MN+5],V[MN+5];
long long ans=1e18,h[MN+5],H[MN+5];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i)
    {
        v[i]=max(v[i-1]+1,a[i]);
        h[i]=h[i-1]+v[i]-a[i];
    }
    for(int i=n;i;--i) V[i]=max(V[i+1]+1,a[i]),H[i]=H[i+1]+V[i]-a[i];
    for(int i=1;i<=n;++i) ans=min(ans,h[i-1]+H[i+1]+max(0,max(v[i-1],V[i+1])+1-a[i]));
    cout<<ans;
    return 0;
}