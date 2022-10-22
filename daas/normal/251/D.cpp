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
#define int long long
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
int n,a[MAXN],all,basis[100],z[100],top=-1,basis_p[100],ans[MAXN],Basis[100],state;
signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read(),all^=a[i];
		int P=0;
		for(int j=62;j>=0;--j) if(a[i]&(1ll<<j))
		{
			if(!basis[j]) {z[++top]=i,basis[j]=a[i],basis_p[j]=(P|(1ll<<top));break;}
			a[i]^=basis[j],P^=basis_p[j];
		}
	}
	int P=0,V=0;
	for(int p=0;p<2;++p)
		for(int i=62;i>=0;--i) if(((all>>i)&1)==p)
		{
			state|=(1ll<<i);
			memset(Basis,0,sizeof(Basis));
			for(int j=0;j<=62;++j)
			{
				int tmp=(basis[j]&state);
				for(int k=62;k>=0 && tmp;--k) if(tmp&(1ll<<k))
				{
					if(!Basis[k]) {Basis[k]=tmp;break;}
					tmp^=Basis[k];
				}
			}
			int chk=V^((p^1)<<i);
			for(int j=62;j>=0;--j) if(chk&(1ll<<j)) chk^=Basis[j];
			if(!chk) V^=((p^1)<<i);
			else V^=(p<<i);
		}
	for(int i=62;i>=0;--i) if(V&(1ll<<i)) V^=basis[i],P^=basis_p[i];
	for(int i=0;i<=top;++i) if(P&(1ll<<i)) ans[z[i]]=1;
	for(int i=1;i<=n;++i)
		if(ans[i]) printf("1 ");
		else printf("2 ");
	putchar('\n');
	return 0;
}
//ore no turn,draw