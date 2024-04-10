#include<bits/stdc++.h>
#define rint register int
#define deb(x) cerr<<#x<<" = "<<(x)<<'\n';
using namespace std;
typedef long long ll;
using pii = pair <ll,ll>;
const int maxn = 5e3 + 5;
int k, a[16][maxn], cnt[16];
ll sum[16], tot, vis;
unordered_map <ll, ll> mp1, mp2;
vector <pii> f[1<<16], tmp, ans[16];
 
int main() {
	scanf("%d", &k);
	for(int i=1; i<=k; i++){
		scanf("%d", cnt+i);
		for(int j=1; j<=cnt[i]; j++){
			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
			mp1[a[i][j]] = i;
		}
		tot += sum[i];
	}
	if(tot % k) {
		puts("No");
		return 0;
	}
	tot /= k;
	for(int i=1; i<=k; i++)
		for(int j=1; j<=cnt[i]; j++)
			if(mp1[ tot-sum[i]+a[i][j] ]) mp2[a[i][j]] = tot-sum[i]+a[i][j];
			else mp2[a[i][j]] = 9e9;
			
	for(int i=1; i<=k; i++)
		for(int j=1; j<=cnt[i]; j++){
			ll s = 1 << (i - 1), x = mp2[a[i][j]];
			tmp.clear(); tmp.push_back({i, x});
			while(x!=9e9 && !(s&(1<<mp1[x]-1)))
				s |= (1<<mp1[x]-1), tmp.push_back({mp1[x], mp2[x]}), x = mp2[x];
			if(x==a[i][j]) f[s] = tmp;
		}
		
	for(int msk=0; msk<1<<k; msk++){
		if(f[msk].size()) continue;
		for(int i=msk; i; i=(i-1)&msk)
			if(f[i].size() && f[i^msk].size()){
				for(auto j : f[i]) f[msk].push_back(j);
				for(auto j : f[i^msk]) f[msk].push_back(j);
				break;
			}
	}
	if(!f[(1<<k)-1].size()) {
		puts("No");
		return 0;
	}
	puts("Yes");
	for(auto i : f[(1<<k)-1]) ans[mp1[ i.second ]].push_back(i);
	for(int i=1; i<=k; i++) printf("%lld %lld\n", ans[i][0].second, ans[i][0].first);
}