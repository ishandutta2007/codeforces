#include<cstdio>
using namespace std;
const int N=200010;
long long n,m,a1[N],a2[N],ans,next[N],j;
char c1[N],c2[N];
inline void solve()
{
	if (m==0)
	{
		for (int i=1;i<=n;i++)
			if (c1[i]==c2[0]&&a1[i]>=a2[0])
				ans+=a1[i]-a2[0]+1;
		return;
	}
	if (m<0)return;
	for (int i=2;i<=m-1;i++)
	{
		while(j>0&&(c2[j+1]!=c2[i]||a2[j+1]!=a2[i]))j=next[j];
		if (c2[j+1]==c2[i]&&a2[j+1]==a2[i])j++;
		next[i]=j;
	}
	j=0;
	for (int i=1;i<=n;i++)
	{
		while(j>0&&(c2[j+1]!=c1[i]||a2[j+1]!=a1[i]))j=next[j];
		if (c2[j+1]==c1[i]&&a2[j+1]==a1[i])j++;
		if (j==m-1)
		{
			int x=i-m+1;
			if (c1[x]==c2[0]&&c1[i+1]==c2[m]&&a1[x]>=a2[0]&&a1[i+1]>=a2[m])
				ans++;
			j=next[j];
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		j++;
		scanf("%lld-%c",&a1[j],&c1[j]);
		if (c1[j]==c1[j-1])
			a1[j-1]+=a1[j],j--;
	}
	n=j;
	j=-1;
	for (int i=1;i<=m;i++)
	{
		j++;
		scanf("%lld-%c",&a2[j],&c2[j]);
		if (c2[j]==c2[j-1])
			a2[j-1]+=a2[j],j--;
	}
	m=j;
	j=0;
	solve();
	printf("%lld",ans);
}