#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
pair<int,int> v[10000007];
int b[1000006],cnt[1000006];
int main(){
	int a[10]; rep(i,1,6) cin>>a[i];
	int n,m=0; cin>>n; rep(i,1,n) scanf("%d",&b[i]);
	rep(i,1,n) rep(j,1,6) v[++m]=mp(b[i]-a[j],i);
	sort(v+1,v+1+m); int ans=2e9;
	for (int i=1,j=0,c=0;i<=m;++i){
		while (c<n&&j<=m) 
			if ((++cnt[v[++j].se])==1) ++c;
		if (j>m) break;
		ans=min(ans,v[j].fi-v[i].fi);
		if ((--cnt[v[i].se])==0) --c;
	}
	cout<<ans<<endl;
	return 0;
}