#include<bits/stdc++.h>
#define int long long
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int l[5000003],r[5000003],val[5000003],ans[5000003],mx[5000003],a[1000003],cnt=1;
long long sum[5000003];
void update(int L,int R,int& p,int id)
{
    if(L==R)
    {
    	++val[id],sum[id]+=p;
        return ;
    }
    int mid=(L+R)>>1;
    if(p<=mid) (!l[id])&&(l[id]=++cnt),update(L,mid,p,l[id]);
    else (!r[id])&&(r[id]=++cnt),update(mid+1,R,p,r[id]);
    val[id]=val[l[id]]+val[r[id]],sum[id]=sum[l[id]]+sum[r[id]];
    return ;
}
void update0(int L,int R,int& p,int id)
{
    if(L==R)
    {
    	--val[id],sum[id]-=p;
        return ;
    }
    int mid=(L+R)>>1;
    if(p<=mid) (!l[id])&&(l[id]=++cnt),update0(L,mid,p,l[id]);
    else (!r[id])&&(r[id]=++cnt),update0(mid+1,R,p,r[id]);
    val[id]=val[l[id]]+val[r[id]],sum[id]=sum[l[id]]+sum[r[id]];
    return ;
}
double query(int L,int R,int x)
{
	int now=1,sz=0,fs=0;
    while(L<R)
    {
		double m=(L+R)/2;
		if(x>=m*(sz+val[l[now]])-fs-sum[l[now]]) L=m+1,fs+=sum[l[now]],sz+=val[l[now]],now=r[now];
		else R=m,now=l[now];
	}
	return (x-(L*(sz+val[l[now]])-fs-sum[l[now]]))*1.0/sz+L;
}
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=1; i<=n; i++) update(0,10000000000000ll,a[i],1);
    for(long long op,v,i,x;m--;)
    {
    	op=read();
    	if(op==1) i=read(),x=read(),update0(0,10000000000000ll,a[i],1),update(0,10000000000000ll,x,1),a[i]=x;
		else v=read(),printf("%.10lf\n",query(0,10000000000000ll,v));
	}
	return 0;
}