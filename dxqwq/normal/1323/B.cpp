#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=400005;
int n,m,k,a[N],b[N],f[N],cnt,ans;
map<int,int>mp[2];
#define IT map<int,int>::iterator
signed main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=sqrt(k);++i) {
		if(k%i)continue;
		f[++cnt]=i;
		if(i*i!=k)f[++cnt]=k/i;
	}
	sort(f+1,f+cnt+1);
	int sum=0;
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		if(!a[i]&&sum) {
			++mp[0][sum];
			sum=0;
		} else if(a[i])++sum;
	}
	if(sum)++mp[0][sum];
	sum=0;
	for(int i=1;i<=m;++i)  {
		scanf("%lld",&b[i]);
		if(!b[i]&&sum) {
			++mp[1][sum];
			sum=0;
		} else if(b[i])++sum;
	}
	if(sum)++mp[1][sum];
	for(IT i1=mp[0].begin();i1!=mp[0].end();++i1) 
		for(IT i2=mp[1].begin();i2!=mp[1].end();++i2)
			for(int i=1;i<=cnt;++i) {
				int j=f[i],l=k/f[i];
				if(j>i1->first||l>i2->first)continue;
				ans+=(i1->first-j+1)*i1->second*(i2->first-l+1)*i2->second;
			}
	printf("%lld\n",ans);
	return 0;
}