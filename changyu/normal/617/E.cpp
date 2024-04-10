#include<cstdio>
#include<algorithm>
#define P(i)((i+D-1)/D)
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
const int N=1e5+9,D=320;
struct query{int l,r,p;}q[N];
bool Cmp(query a,query b){return P(a.l)==P(b.l)?a.r<b.r:a.l<b.l;}
int a[N],n,m,c,L,R,b[1<<20];long long t,ans[N];
int main()  
{
	n=read();m=read();c=read();n++;
	for(int i=2;i<=n;i++)a[i]=read()^a[i-1];
	for(int k=1;k<=m;k++)q[k].l=read(),q[k].r=read()+1,q[k].p=k;
	std::sort(q+1,q+m+1,Cmp);
	L=R=1,b[a[1]]++;
	for(int k=1;k<=m;k++){
	  for(;R<q[k].r;R++)t+=b[a[R+1]^c],b[a[R+1]]++;
	  for(;L>q[k].l;L--)t+=b[a[L-1]^c],b[a[L-1]]++;
	  for(;R>q[k].r;R--)b[a[R]]--,t-=b[a[R]^c];
	  for(;L<q[k].l;L++)b[a[L]]--,t-=b[a[L]^c];
	  ans[q[k].p]=t;
	}for(int k=1;k<=m;k++)printf("%I64d\n",ans[k]);
	return 0;
}