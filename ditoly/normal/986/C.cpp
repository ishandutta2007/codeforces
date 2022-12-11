#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 22
int n,f[1<<MN],a[1<<MN],b[1<<MN],c[1<<MN],d[1<<MN];
int gf(int k){return f[k]<0?k:f[k]=gf(f[k]);}
inline void merge(int x,int y){if(gf(x)!=gf(y))f[gf(x)]=gf(y);}
void solve(int x,int y)
{
	if(!b[y])return;
	if(d[y]>=0){merge(x,d[y]);return;}
	d[y]=x;
	if(c[y]>=0)merge(x,c[y]);
	for(int i=0;i<n;++i)if(y&(1<<i))solve(x,y^(1<<i));
}
int main()
{
	int m,i,j,ans=0;
	n=read();m=read();
	memset(f,-1,sizeof(f));memset(c,-1,sizeof(c));memset(d,-1,sizeof(d));
	for(i=0;i<m;++i)++b[a[i]=read()],c[a[i]]=i;
	for(i=0;i<1<<n;++i)if(b[i])for(j=0;j<n;++j)b[i|(1<<j)]=1;
	for(i=0;i<m;++i)solve(i,((1<<n)-1)^a[i]);
	for(i=0;i<m;++i)if(gf(i)==i)++ans;
	printf("%d",ans);
}