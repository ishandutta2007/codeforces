#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int A[100010],B[100010];
char c[100010],d[100010];
int n,m;
int inv[100010],jc[100010],jcv[100010];
void init()
{
	jc[1]=jc[0]=jcv[0]=jcv[1]=inv[1]=1;
	for(int i=2;i<=100000;++i)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		jcv[i]=1ll*jcv[i-1]*inv[i]%mod;	
	}
}
int C(int a,int b)
{
	if(a<0||b<0||a<b)return 0;
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
int calc(int a,int b)
{
	if(!a&&!b)return 1;
	return C(a+b-1,b-1);
}
int solve(int w,int f[],int a,int b,int c,int d)
{
	++b;
	int ret=1ll*calc(a,c)*calc(d,b)%mod;
//	printf("%d\n",ret);
	if(w>a+b+c+d)return ret;
	if(w<a+b+c+d)return 0;
	for(int i=2;i<=w;++i)
	{
		f[i-1]?--d:--b;
	//	printf("%d\n",ret);
	//	printf("%d %d %d %d\n",a,b,c,d);
		if(f[i])continue;
		(ret+=mod-1ll*calc(a,c)*calc(d,b)%mod)>=mod?ret-=mod:0;
		f[i-1]?++d:++b;
		f[i-1]?--c:--a;
	}
	return ret;
}
int main()
{
	init();
	scanf("%s %s",c+1,d+1);
	n=strlen(c+1);
	m=strlen(d+1);
	for(int i=1;i<=n;++i)
		A[i]=c[i]-'0';
	for(int i=1;i<=m;++i)
		B[i]=d[i]-'0';
	A[n]--;
	for(int i=n;i>=1;--i)
		if(A[i]<0)
		{
			A[i-1]--;
			A[i]=1;	
		}
	if(!A[1])
	{
		for(int i=1;i<n;++i)
			A[i]=A[i+1];
		--n;
	}
//	reverse(A+1,A+1+n);
//	reverse(B+1,B+1+m);
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(b<c-1||b>c)
	{
		printf("0");
		return 0;	
	}
	int ans=solve(m,B,a,b,c,d);
//	printf("%d\n",ans);
	ans+=mod-solve(n,A,a,b,c,d);
	ans>=mod?ans-=mod:0;
	printf("%d",ans);
	return 0;
}