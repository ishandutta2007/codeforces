#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int L,R,lim,pd[110],prime[110],cnt,ans,num[2944750],tot,dp[2944750],vis[2944750];
void fun(int val,int k)
{
	if(k==cnt+1) {num[++tot]=val;return;}
	fun(val,k+1);
	while((ll)val*prime[k]<=R) val*=prime[k],fun(val,k+1);
}
int main()
{
	L=read(),R=read(),lim=read();
	//L=1000000000,R=1000000000,lim=100;
	for(int i=2;i<=100;++i)
	{
		if(!pd[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt && prime[j]*i<=100;++j)
		{
			pd[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	fun(1,1);
	sort(num+1,num+tot+1);
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for(register int i=2;i<=lim;++i)
		for(register int j=1,cur=0;j<=tot;++j) if(num[j]%i==0)
		{
			while(num[cur]*i<num[j]) ++cur;
			dp[j]=min(dp[j],dp[cur]+1);
			if(dp[j]+i<=lim) vis[j]=1;
		}
	for(int i=1;i<=tot;++i) if(vis[i] && num[i]>=L) ++ans;
	printf("%d\n",ans);
	//cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}
//ore no turn,draw!