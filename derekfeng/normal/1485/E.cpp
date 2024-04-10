#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int T,n,a[200004],x,depth,d[200004];
vector<int>g[200004];
vector<pii>v[200004];
void init(int x,int par,int dep){
	v[dep].push_back(mkp(a[x],x));
	for(auto y:g[x])if(y!=par)init(y,x,dep+1);
	depth=max(depth,dep),d[x]=dep;
}
ll ans,f[200004],tmp[200004];
void dp(int dep){
	if(dep==depth){
		for(auto x:v[dep])f[x.se]=max(x.fi-v[dep].front().fi,v[dep].back().fi-x.fi);
		return;
	}
	dp(dep+1);
	for(auto x:v[dep]){
		tmp[x.se]=0;
		for(auto y:g[x.se])if(d[y]>dep)tmp[x.se]=max(tmp[x.se],f[y]);
		f[x.se]=tmp[x.se]+max(x.fi-v[dep].front().fi,v[dep].back().fi-x.fi);
	}
	ll num=tmp[v[dep].front().se];
	for(int i=1;i<v[dep].size();i++){
		pii x=v[dep][i];
		num+=x.fi-v[dep][i-1].fi;
		f[x.se]=max(f[x.se],num);
		num=max(num,tmp[x.se]);
	}
	num=tmp[v[dep].back().se];
	for(int i=(int)v[dep].size()-2;i>=0;i--){
		pii x=v[dep][i];
		num+=v[dep][i+1].fi-x.fi;
		f[x.se]=max(f[x.se],num);
		num=max(num,tmp[x.se]);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);depth=0;ans=0;
		for(int i=1;i<=n;i++)g[i].clear(),v[i].clear();
		for(int i=2;i<=n;i++)scanf("%d",&x),g[x].push_back(i),g[i].push_back(x);
		for(int i=2;i<=n;i++)scanf("%d",&a[i]);
		init(1,0,0);
		for(int i=1;i<=depth;i++)sort(v[i].begin(),v[i].end());
		dp(1);
		for(auto x:v[1])ans=max(ans,f[x.se]);
		printf("%I64d\n",ans);
	}
}