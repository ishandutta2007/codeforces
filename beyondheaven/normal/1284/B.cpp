#include<cstdio>
#include<algorithm>
#define MaxN 1000123
template<typename T>
inline void read(T&x)
{
	x=0;int ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58)x=10*x+ch-48,ch=getchar();
}
typedef long long LL;
using std::min;
using std::max;
LL ans;
int n,l,cnt;
int s[MaxN];
bool flag[MaxN];
int minv[MaxN],maxv[MaxN];
int c[MaxN];
inline bool Check()
{
	int v=0x3f3f3f3f;
	for(int i=1;i<=l;++i)
	if(s[i]>v)return true;
	else v=s[i];
	return false;
}
inline void Init()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(l);
		minv[i]=0x3f3f3f3f;
		for(int j=1;j<=l;++j)
		{
			read(s[j]);
			minv[i]=min(minv[i],s[j]);
			maxv[i]=max(maxv[i],s[j]);
		}
		flag[i]=Check();
		if(flag[i])++cnt;
	}
}
inline void Solve()
{
	ans+=1LL*cnt*(2*n-cnt);
	for(int i=1;i<=n;++i)
	if(!flag[i])++c[maxv[i]];
	for(int i=1;i<=1000000;++i)c[i]+=c[i-1];
	for(int i=1;i<=n;++i)
	if(!flag[i])ans+=n-cnt-c[minv[i]];
	printf("%lld\n",ans);
}
int main()
{
	Init();
	Solve();
	return 0;
}