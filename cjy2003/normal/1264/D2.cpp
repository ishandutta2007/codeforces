#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
char s[1000010];
int n,jc[1000010],jcv[1000010];
int pre[2][1000010],ans;
inline int C(int a,int b){return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int a=0,b=0,c=0,d=0;
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[n]=kpow(jc[n],mod-2);
	for(int i=n;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
	for(int i=1;i<=n;++i)d+=s[i]=='?',c+=s[i]==')';
	if(d)
	{
		pre[0][0]=1;
		for(int j=1;j<d;++j)pre[0][j]=pl(pre[0][j-1],C(d-1,j));
	}
	pre[1][0]=1;
	for(int j=1;j<=d;++j)pre[1][j]=pl(pre[1][j-1],C(d,j));
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')++a;
		else if(s[i]=='?')++a,--d;
		else --c;
	//	printf("%d %d %d %d\n",a,b,c,d);
		if(s[i]=='('&&c+d>=a)add(ans,pre[1][min(c+d-a,b+d)]);
		else if(s[i]=='?'&&c+d>=a)add(ans,pre[0][min(c+d-a,b+d)]);
		if(s[i]=='?')--a,++b;
	}
	printf("%d",ans);
	return 0;
}