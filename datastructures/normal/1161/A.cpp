#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
#define int long long
using namespace std;
int n,k,a[500005],f[500005],g[500005],cnt[500005];
int ans;
signed main(){
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		if (f[a[i]]==0)f[a[i]]=i;
		g[a[i]]=i;
		cnt[a[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (f[i]==0)f[i]=k+1;
		if (i>1&&f[i]>g[i-1])ans++;
		if (i<n&&f[i]>g[i+1])ans++;
		if (cnt[i]==0)ans++;
	}
	cout<<ans<<endl;
	return 0;
}