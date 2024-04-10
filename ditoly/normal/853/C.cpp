#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
#define N 262144
int p[MN+5],l[MN+5],d[MN+5],r[MN+5],u[MN+5],a[MN+5],t[N*2+5];
ll ans[MN+5];
void inc(int k){for(k+=N;k;k>>=1)++t[k];}
int query(int l,int r)
{
	int res=0;
	if(l<=r)for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res+=t[l+1];
		if( r&1)res+=t[r-1];
	}
	return res;
}
bool cmp1(int a,int b){return l[a]<l[b];}
bool cmp2(int a,int b){return r[a]>r[b];}
inline ll f(ll x){return x*(x-1)/2;}
int main()
{
	int n=read(),q=read(),i,j;
	for(i=1;i<=n;++i)p[i]=read();
	for(i=1;i<=q;++i)l[i]=read(),d[i]=read(),r[i]=read(),u[i]=read(),a[i]=i;
	sort(a+1,a+q+1,cmp1);
	for(i=j=1;i<=n;inc(p[i++]))for(;j<=q&&i==l[a[j]];++j)ans[a[j]]+=f(query(1,d[a[j]]-1))+f(query(u[a[j]]+1,n));
	memset(t,0,sizeof(t));
	sort(a+1,a+q+1,cmp2);
	for(i=n,j=1;i;inc(p[i--]))for(;j<=q&&i==r[a[j]];++j)ans[a[j]]+=f(query(1,d[a[j]]-1))+f(query(u[a[j]]+1,n));
	for(i=1;i<=q;++i)printf("%I64d\n",f(n)-f(l[i]-1)-f(n-r[i])-f(d[i]-1)-f(n-u[i])+ans[i]);
}