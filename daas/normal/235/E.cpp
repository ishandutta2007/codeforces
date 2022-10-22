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
const int mod=(1<<30);
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int A,B,C,num[4000010],ans,miu[2010],prime[2010],cnt,pd[2010],val1[4000010],val2[2010];
int main()
{
	A=read(),B=read(),C=read();
	for(int i=1;i<=A;++i)
		for(int j=1;j<=B;++j)
			++num[i*j];
	miu[1]=1;
	for(int i=2;i<=C;++i)
	{
		if(!pd[i]) miu[i]=MOD(-1),prime[++cnt]=i;
		for(int j=1;j<=cnt && prime[j]*i<=C;++j)
		{
			miu[i*prime[j]]=MOD(-miu[i]);
			pd[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<=A*B;++i)
		for(int j=i;j<=A*B;j+=i)
			val1[i]+=num[j];
	for(int i=1;i<=C;++i) val2[i]=C/i;
	for(int i=1;i<=C;++i)
	{
		int v1=0,v2=0;
		for(int j=i;j<=A*B;j+=i) v1+=val1[j];
		for(int j=i;j<=C;j+=i) v2+=val2[j];
		ans=MOD(ans+(ll)v1*v2%mod*miu[i]%mod-mod);
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw