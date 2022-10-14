#include<bits/stdc++.h>
#define int long long 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[200003],st[200003][23],qwq[200003][23],n=read();
inline void init(int l)
{
	st[l][0]=a[l],qwq[l][0]=a[l];
	for(int i=1; i<=20; i++) 
    st[l][i]=max(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]),
    qwq[l][i]=qwq[l][i-1]|qwq[min(l+(1<<(i-1)),n)][i-1];
}
inline int query(int l,int r)
{
	int L=log(r-l+1)/log(2);
	return max(st[l][L],st[min(r-(1<<L)+1,n)][L]);
}
inline int qwqry(int l,int r)
{
	int L=log(r-l+1)/log(2);
	return qwq[l][L]|qwq[min(r-(1<<L)+1,n)][L];
}
long long bs(int x)
{
    int l,r,ans1=x,ans2=x;
    l=1,r=x-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(query(mid,x-1)<a[x] && qwqry(mid,x)<=a[x]) ans1=mid,r=mid-1; else l=mid+1;
    }
    l=x+1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(query(x+1,mid)<=a[x] && qwqry(x,mid)<=a[x]) ans2=mid,l=mid+1; else r=mid-1;
    }
    return (ans2-x+1)*(x-ans1+1);
}
signed main()
{
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=n; i>=1; i--) init(i);
    long long ans=1LL*n*(n+1LL)/2LL;
    for(int i=1; i<=n; i++) ans-=bs(i);
    cout<<ans<<endl;
    return 0;
}