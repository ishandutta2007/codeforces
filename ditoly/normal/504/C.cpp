#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int a[MN+5],s[MN+5];
int main()
{
	int n=read(),i,j,k;long long ans=0;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<n+1-i;++i)if(a[i]!=a[n+1-i])break;
	if(i>=n+1-i)return 0*printf("%I64d",1LL*n*(n+1)/2);
	for(j=n/2;;--j)if(a[j]!=a[n+1-j])break;
	for(k=i;k<=j;++k)++s[a[k]],--s[a[n+1-k]];
	for(k=1;k<=n;++k)if(s[k])break;
	if(k>n)ans+=2LL*i*(n/2+1-j);
	memset(s,0,sizeof(s));
	for(k=i;k<=n+1-i;++k)++s[a[k]];
	for(k=1,j=0;k<=n;++k)j+=s[k]&1;
	if(j==(n&1))
	{
		ans+=1LL*i*i;
		for(k=i;k<n+1>>1;++k)if((s[a[k]]-=2)<0)break;else ans+=i;
		memset(s,0,sizeof(s));
		for(k=i;k<=n+1-i;++k)++s[a[k]];
		for(k=i;k<n+1>>1;++k)if((s[a[n+1-k]]-=2)<0)break;else ans+=i;
	}
	printf("%I64d",ans);
}