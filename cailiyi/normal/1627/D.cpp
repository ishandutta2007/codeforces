#include<bits/stdc++.h>
#define N 1000000
using namespace std;
int n,s[N+5],p[N+5],cnt,ans;
bool vis[N+5];
inline bool check(int x)
{
	if(!s[x]) return 0;
	for(int i=1;i<=cnt && 1ll*x*p[i]<=N;++i)
		if(!(s[x]-s[x*p[i]])) return 0;
	return 1;
}
int main()
{
	for(int i=2;i<=N;++i)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;j<=cnt && 1ll*i*p[j]<=N;++j)
		{
			vis[i*p[j]]=1;
			if(!(i%p[j])) break;
		}
	}
	scanf("%d",&n);
	for(int i=1,a;i<=n;++i)
		scanf("%d",&a),++s[a];
	for(int i=1;i<=cnt;++i)
		for(int j=N/p[i];j;--j)
			s[j]+=s[j*p[i]];
	for(int i=1;i<=N;++i) ans+=check(i);
	printf("%d",ans-n);
	return 0;
}