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
const int mod=1e9+7;
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
int k,pa,pb,dp[1010][1010],P,inv;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
int fun(int x,int y)
{
	if(x==k) return MOD(MOD(y+k-mod)+(ll)P*inv%mod-mod);
	if(y>=k) return y;
	if(dp[x][y]!=-1) return dp[x][y];
	int bck=MOD((ll)P*fun(x+1,y)%mod+(ll)MOD(1-P)*fun(x,x+y)%mod-mod);
	return dp[x][y]=bck;
}
int main()
{
	k=read(),pa=read(),pb=read();
	P=(ll)pa*ksm(pa+pb,mod-2)%mod;
	inv=ksm(MOD(1-P),mod-2);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",fun(1,0));
	return 0;
}
//ore no turn,draw!