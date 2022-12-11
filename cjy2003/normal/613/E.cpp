#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
const unsigned long long sed=131;
char s1[2020],s2[2020],t[2020];
int n,k,ans;
unsigned long long po[2020];
struct HAS
{
	unsigned long long has1[2020],has2[2020];
	void init(char s[])
	{
		int len=strlen(s+1);
		for(int i=1;i<=len;++i)has1[i]=has1[i-1]*sed+s[i];
		for(int i=len;i>=1;--i)has2[i]=has2[i+1]*sed+s[i];
	}
	unsigned long long get1(int l,int r)
	{
		return has1[r]-has1[l-1]*po[r-l+1];
	}
	unsigned long long get2(int l,int r)
	{
		return has2[l]-has2[r+1]*po[r-l+1];
	}
}h1,h2,ht;
int dp[2][2020][2][2];
void work()
{
	h1.init(s1);
	h2.init(s2);
	ht.init(t);
	int T=0;
	memset(dp[T],0,sizeof(dp[T]));
	for(int i=n;i;--i)
	{
		T^=1;
		memset(dp[T],0,sizeof(dp[T]));
		for(int l=2;2*l<=k&&i+l-1<=n;++l)
		{
			if(h1.get1(i,i+l-1)*po[l]+h2.get2(i,i+l-1)==ht.get1(k-2*l+1,k))dp[T][k-2*l+1][0][1]=1;
			if(h2.get1(i,i+l-1)*po[l]+h1.get2(i,i+l-1)==ht.get1(k-2*l+1,k))dp[T][k-2*l+1][1][1]=1;
		}
		if(s1[i]==t[k])dp[T][k][0][0]=1;
		if(s2[i]==t[k])dp[T][k][1][0]=1;
		for(int j=k-1;j;--j)
		{
			if(s1[i]==t[j])add(dp[T][j][0][0],dp[T^1][j+1][0][0]),add(dp[T][j][0][0],dp[T^1][j+1][0][1]),add(dp[T][j][0][1],dp[T][j+1][1][0]);
			if(s2[i]==t[j])add(dp[T][j][1][0],dp[T^1][j+1][1][0]),add(dp[T][j][1][0],dp[T^1][j+1][1][1]),add(dp[T][j][1][1],dp[T][j+1][0][0]);
		}
	//	for(int j=1;j<=k;++j)printf("%d %d %d %d %d %d\n",i,j,dp[T][j][0][0],dp[T][j][0][1],dp[T][j][1][0],dp[T][j][1][1]);
		if(s1[i]==t[1])
		{
			add(ans,dp[T][1][0][0]);
			add(ans,dp[T][1][0][1]);
			for(int l=2;2*l<k&&i-l>=0;++l)
				if(h1.get2(i-l+1,i)*po[l]+h2.get1(i-l+1,i)==ht.get1(1,2*l))add(ans,dp[T][2*l][1][0]);
		}
		if(s2[i]==t[1])
		{
			add(ans,dp[T][1][1][0]);
			add(ans,dp[T][1][1][1]);
			for(int l=2;2*l<k&&i-l>=0;++l)
				if(h2.get2(i-l+1,i)*po[l]+h1.get1(i-l+1,i)==ht.get1(1,2*l))add(ans,dp[T][2*l][0][0]);
		}
	}
}
int main()
{
	scanf("%s %s %s",s1+1,s2+1,t+1);
	n=strlen(s1+1);
	k=strlen(t+1);
	if(k==1)
	{
		for(int i=1;i<=n;++i)ans+=t[1]==s1[i],ans+=t[1]==s2[i];
		printf("%d",ans);
		return 0;
	}
	if(k==2)
	{
		for(int i=1;i<=n;++i)
		{
			ans+=t[1]==s1[i]&&t[2]==s1[i+1];
			ans+=t[1]==s1[i]&&t[2]==s1[i-1];
			ans+=t[1]==s2[i]&&t[2]==s2[i+1];
			ans+=t[1]==s2[i]&&t[2]==s2[i-1];
			ans+=t[1]==s1[i]&&t[2]==s2[i];
			ans+=t[1]==s2[i]&&t[2]==s1[i];
		}
		printf("%d",ans);
		return 0;
	}
	po[0]=1;
	for(int i=1;i<=2000;++i)po[i]=po[i-1]*sed;
	work();
//	printf("%d\n",ans);
	reverse(s1+1,s1+1+n);
	reverse(s2+1,s2+1+n);
	work();
	printf("%d",ans);
	return 0;
}