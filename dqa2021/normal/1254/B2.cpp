#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}
typedef long long ll;

int n,a[1000010],b[1000010]; ll sum;
ll ans=5e18;
int getdis(int x,int y)
{
	return x<y?y-x:x-y;
}
ll check(ll x)
{
	for (int i=1;i<=n;i++) b[i]=a[i]%x;
	ll res=0;
	for (int i=1,j;i<=n;i=j)
	{
		ll subsum=b[i];
		for (j=i;j<n&&subsum<x;j++,subsum+=b[j]);
		if (subsum<x) break;
		int midpos=-1; ll tmp=0;
		for (int u=i;u<=j;u++)
		{
			tmp+=b[u];
			if (tmp>=(x+1>>1))
			{
				midpos=u; break;
			}
		}
		subsum=x;
		for (int u=i;u<=j;u++)
		{
			tmp=min(1LL*b[u],subsum);
			res+=tmp*getdis(u,midpos);
			subsum-=tmp; b[u]-=tmp;
		}
	}
	return res;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	if (sum==1) return puts("-1"),0;
	for (int i=2;i<=sum&&i<=1000000;i++)
		if (sum%i==0)
		{
			ans=min(ans,check(i));
			while (sum%i==0) sum/=i;
		}
	if (sum^1) ans=min(ans,check(sum));
	printf("%I64d\n",ans);
	return 0;
}