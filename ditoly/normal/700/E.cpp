#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 200000
#define K 18
#define N 262144
char s[MN+5];
int v[MN+5],A[MN*4+20],*sa=A,*nsa=sa+MN+5,*rk=nsa+MN+5,*nrk=rk+MN+5;
int n,h[K][MN+5],lg[MN+5],t[N*2+5];
int rmq(int l,int r)
{
	int x=lg[r-l+1];
	return min(h[x][l],h[x][r-(1<<x)+1]);
}
void renew(int k,int x){for(k+=N;k;k>>=1)t[k]=min(t[k],x);}
int query(int l,int r)
{
	int res=t[0];
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=min(res,t[l+1]);
		if( r&1)res=min(res,t[r-1]);
	}
	return res;
}
struct node{int x,l;}T[N*2+5];
node operator+(const node&a,const node&b)
{
	return a.x==b.x?a.l<b.l?a:b:a.x>b.x?a:b;
}
void renew(int l,int r,node x)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)T[l+1]=T[l+1]+x;
		if( r&1)T[r-1]=T[r-1]+x;
	}
}
node query(int k)
{
	node res=(node){0,0};
	for(k+=N;k;k>>=1)res=res+T[k];
	return res;
}
void cal(int x,int k,int&L,int&R)
{
	int l,r,mid;
	for(l=1,r=(L=rk[x])-1;l<=r;)
	{
		mid=l+r>>1;
		if(rmq(mid+1,rk[x])>=k)L=mid,r=mid-1;
		else l=mid+1;
	}
	for(l=(R=rk[x])+1,r=n;l<=r;)
	{
		mid=l+r>>1;
		if(rmq(rk[x]+1,mid)>=k)R=mid,l=mid+1;
		else r=mid-1;
	}
}
int main()
{
	int i,l,L,R,ans=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i)++v[s[i]];
	for(i='a';i<='z';++i)v[i]+=v[i-1];
	for(i=1;i<=n;++i)sa[v[s[i]]--]=i;
	for(i=1;i<=n;++i)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(l=1;l<n;l<<=1,swap(sa,nsa),swap(rk,nrk))
	{
		for(i=1;i<=n;++i)v[rk[sa[i]]]=i;
		for(i=n;i;--i)if(sa[i]>l)nsa[v[rk[sa[i]-l]]--]=sa[i]-l;
		for(i=0;i<l;++i)nsa[v[rk[n-i]]--]=n-i;
		for(i=1;i<=n;++i)nrk[nsa[i]]=nrk[nsa[i-1]]+
			(rk[nsa[i]]!=rk[nsa[i-1]]||rk[nsa[i]+l]!=rk[nsa[i-1]+l]);
	}
	for(i=1,l=0;i<=n;++i,l?--l:0)if(rk[i]>1)
		{while(s[i+l]==s[sa[rk[i]-1]+l])++l;h[0][rk[i]]=l;}
	for(l=1;l<K;++l)for(i=1;i<=n;++i)h[l][i]=min(h[l-1][i],h[l-1][i+(1<<l-1)]);
	for(i=3;i<=n;++i)lg[i]=lg[i+1>>1]+1;
	memset(t,40,sizeof(t));
	for(i=n;i;--i)
	{
		node x=query(rk[i]);
		if(x.x)cal(i,x.l,L,R),x.l+=query(L,R)-i;
		else x=(node){0,1};
		ans=max(ans,++x.x);
		cal(i,x.l,L,R);renew(L,R,x);renew(rk[i],i);
	}
	printf("%d",ans);
}