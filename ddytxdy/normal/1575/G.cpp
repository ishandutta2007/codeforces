#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mo=1e9+7;
int n,ans,a[N],cnt[N],f[N];
vector<int>d,p[N];
int calc()
{
	int s=0;
	for (auto t:d)
		for (auto i:p[t])
		s=(s+1ll*f[i]*(cnt[i]*2+1)%mo)%mo,cnt[i]++;
	for (auto t:d)
		for (auto i:p[t])
		cnt[i]=0;
	return s;
}
int main(){
	for (int i=1;i<=100000;i++)
		for (int j=i;j<=100000;j+=i)
		p[j].emplace_back(i);
	for (int i=1;i<=100000;i++)
	{
		f[i]=i;
		for (auto j:p[i]) if (i^j) f[i]=(f[i]-f[j]+mo)%mo;
	}
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		d.clear();
		for (int j=i;j<=n;j+=i) d.emplace_back(a[j]);
		ans=(ans+1ll*calc()*f[i])%mo;
	}
	printf("%d",ans);
	return 0;
}