#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,f[N],sz[N],a[N];
bool e[N];
ll ans1,ans2;
vector<pair<int,int> >o;
vector<int>tr[N];
int F(int x){
	return x==f[x]?x:f[x]=F(f[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),o.push_back({a[i],i});
		f[i]=i,sz[i]=1;
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back(v),tr[v].push_back(u);
	}
	sort(o.begin(),o.end());
	for(auto [w,x]:o){
		e[x]=1;
		for(auto y:tr[x])if(e[y]){
			int X=F(x),Y=F(y);
			ans1+=(ll)sz[X]*sz[Y]*w;
			f[X]=Y,sz[Y]+=sz[X];
		}
	}
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1,e[i]=0;
	reverse(o.begin(),o.end());
	for(auto [w,x]:o){
		e[x]=1;
		for(auto y:tr[x])if(e[y]){
			int X=F(x),Y=F(y);
			ans2+=(ll)sz[X]*sz[Y]*w;
			f[X]=Y,sz[Y]+=sz[X];
		}
	}
	printf("%lld",ans1-ans2);
}