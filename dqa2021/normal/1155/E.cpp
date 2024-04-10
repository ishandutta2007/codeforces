#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e6+3;

int n,a[20][20],b[20],pos[20],ans[20];
int ifac[1000010];
int main()
{
	ifac[1]=1;
	for (int i=2;i<Mod;i++) ifac[i]=1LL*(Mod-Mod/i)*ifac[Mod%i]%Mod;
	n=11;
	for (int i=1;i<=11;i++)
	{
		pos[i]=i;
		for (int j=1,u=1;j<=11;j++,u=1LL*u*i%Mod)
			a[i][j]=u;
		printf("? %d\n",i); fflush(stdout);
		scanf("%d",b+i);
	}
	for (int i=1;i<=n;i++)
	{
		int maxpos=-1;
		for (int j=i;j<=n;j++)
			if (a[i][j])
			{
				maxpos=j; break;
			}
		//assert(~maxpos);
		if (i^maxpos)
		{
			swap(pos[i],pos[maxpos]);
			for (int j=1;j<=n;j++) swap(a[j][i],a[j][maxpos]);
		}
		for (int j=i+1;j<=n;j++)
		{
			int tmp=1LL*a[j][i]*ifac[a[i][i]]%Mod;  //caution negative
			for (int u=i;u<=n;u++) a[j][u]=((a[j][u]-1LL*tmp*a[i][u])%Mod+Mod)%Mod;
			b[j]=((b[j]-1LL*tmp*b[i])%Mod+Mod)%Mod;
		}
	}
	for (int i=n;i;i--)
	{
		for (int j=i+1;j<=n;j++) b[i]=((b[i]-1LL*ans[pos[j]]*a[i][j])%Mod+Mod)%Mod;
		ans[pos[i]]=1LL*b[i]*ifac[a[i][i]]%Mod;
	}
	int res=-1;
	for (int i=0;i<Mod;i++)
	{
		int tmp=0;
		for (int j=1,u=1;j<=11;j++,u=1LL*u*i%Mod)
			tmp=(tmp+1LL*ans[j]*u)%Mod;
		if (!tmp)
		{
			res=i; break;
		}
	}
	printf("! %d\n",res);
	return 0;
}