#include<cstdio>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
typedef long long ll;
const int A=1e6+1,N=3e5+1;
int n,m,d[A],o,l,r,lst[N],nxt[N];ll bt[N],btf[N];
inline int Add(int t,int a,ll*bt){for(;t<=n;t+=t&-t)bt[t]+=a;}
inline ll Sum(int t,ll*bt){ll s=0;for(;t;t-=t&-t)s+=bt[t];return s;}
int main()
{
	int t,s;
	for(int i=1;i<A;i++)
	  for(int j=i;j<A;j+=i)
		d[j]++;
	n=read();m=read();
	for(int i=1,j=0;i<=n;i++)
	{
	  t=read();
	  if(t>2){
		nxt[j]=i,lst[i]=j;
		Add(j+1,i,btf);Add(i+1,-i,btf);
		j=i;
	  }Add(i,t,bt);
	}
	for(;m--;)
	{
	  o=read(),l=read(),r=read();
	  if(o==1)for(int i=Sum(l,btf);i<=r&&i;i=nxt[i]){
		  t=Sum(i,bt)-Sum(i-1,bt);
		  Add(i,d[t]-t,bt);
		  if(t<=2)nxt[lst[i]]=nxt[i],lst[nxt[i]]=lst[i],Add(lst[i]+1,nxt[i]-i,btf),Add(i+1,i-nxt[i],btf);
		}
	  else printf("%I64d\n",Sum(r,bt)-Sum(l-1,bt));
	}return 0;
}