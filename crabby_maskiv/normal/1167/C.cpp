#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int fa[N],size[N],rk[N];
int rt(int u){
	if(fa[u]==u) return u;
	return rt(fa[u]);
}
void merge(int u,int v){
	u=rt(u);v=rt(v);
	if(u==v) return;
	if(size[u]<size[v]) swap(u,v);
	fa[v]=u;size[u]+=size[v];
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		fa[i]=i;
		size[i]=1;
	}
	while(m--){
		int las=0;
		int k;cin>>k;
		while(k--){
			int x;cin>>x;
			if(las) merge(las,x);
			las=x;
		}
	}
	for(i=1;i<=n;i++) cout<<size[rt(i)]<<" ";
	return 0;
}