#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 262144
int s[MN+5],a[MN+5],b[MN+5];
void add(int x){for(;x<=MN;x+=x&-x)++s[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=s[x];return r;}
int query(int x)
{
	int i=18,z=MN;
	while(i--)if((1<<i)-s[z-(1<<i)]<=x)x-=(1<<i)-s[z-(1<<i)];else z-=1<<i;
	return z;
}
int main()
{
	int n=read(),i,x;
	for(i=1;i<=n;++i)a[i]=read(),add(a[i]+1),a[i]-=sum(a[i]);
	memset(s,0,sizeof(s));
	for(i=1;i<=n;++i)b[i]=read(),add(b[i]+1),b[i]-=sum(b[i]);
	for(i=n;i;--i)if((a[i]+=b[i])>=n-i+1)++a[i-1],a[i]-=n-i+1;
	memset(s,0,sizeof(s));
	for(i=1;i<=n;++i)add(x=query(a[i])),printf("%d ",x-1);
}