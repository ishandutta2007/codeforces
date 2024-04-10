#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
const int K=200000;
const ll inf=0x3f3f3f3fll;
int n,m;
ll size[N];
int fa[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
void merge(int u,int v){
	u=rt(u);v=rt(v);
	if(u==v) return;
	fa[u]=v;
	size[v]+=size[u];
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		fa[i+K]=i+K;fa[i]=i;
		size[i]=size[i+K]=1;
	}
	for(i=1;i<n;i++){
		int x,y,z;cin>>x>>y>>z;
		merge(x+z*K,y+z*K);
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		if(fa[i]==i) ans+=size[i]*(size[i]-1);
		if(fa[i+K]==i+K) ans+=size[i+K]*(size[i+K]-1);
	}
	for(i=1;i<=n;i++){
		ans+=(size[rt(i)]-1)*(size[rt(i+K)]-1);
	}
	cout<<ans;
	return 0;
}