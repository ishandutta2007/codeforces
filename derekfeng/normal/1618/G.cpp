#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,q;
pii a[400004];
ll ans[200004],d[400004],sum;
int fa[400004],l[400004],r[400004],s[400004];
vector<pii>v,ask;
int F(int x){
	return fa[x]==x?x:fa[x]=F(fa[x]);
}
ll got(int v){
	return d[r[v]]-d[r[v]-s[v]];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n+m;i++)scanf("%d",&a[i].fi),a[i].se=i;
	sort(a+1,a+n+m+1);
	for(int i=1;i<=n+m;i++){
		d[i]=d[i-1]+a[i].fi;
		fa[i]=i,s[i]=(a[i].se<=n),l[i]=r[i]=i;
		if(s[i]==1)sum+=a[i].fi;
		if(i>1)v.push_back({a[i].fi-a[i-1].fi,i});
	}
	for(int i=1;i<=q;i++){
		int k;scanf("%d",&k);
		ask.push_back({k,i});
	}
	sort(v.begin(),v.end());
	sort(ask.begin(),ask.end());
	int it=0;
	for(auto qr:ask){
		while(it<v.size()&&v[it].fi<=qr.fi){
			int p=v[it].se;
			int U=F(p-1),V=F(p);
			sum-=got(U)+got(V);
			fa[U]=V,s[V]+=s[U],l[V]=l[U];
			sum+=got(V);
			it++;
		}
		ans[qr.se]=sum;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}