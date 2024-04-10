#include<iostream>
using namespace std;
const int o=1010;
int T,n,a[o][o],col[o],fa[o],w[o];
int fr(int x){if(x==fa[x]) return x;int res=fr(fa[x]);w[x]^=w[fa[x]];return fa[x]=res;}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(cin>>T;T--;){
		cin>>n;
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>a[i][j];
		for(int i=1;i<=n;++i) w[fa[i]=i]=0;
		for(int i=1,u,v;i<n;++i) for(int j=i+1;j<=n;++j) if(a[i][j]^a[j][i]){
			if((u=fr(i))==(v=fr(j))){if(w[i]^w[j]) swap(a[i][j],a[j][i]);}
			else if(a[i][j]<a[j][i]) fa[u]=v,w[u]=(w[i]^w[j]);
			else swap(a[i][j],a[j][i]),fa[u]=v,w[u]=(w[i]^w[j]^1);
		}
		for(int i=1;i<=n;++i,cout<<"\n") for(int j=1;j<=n;++j) cout<<a[i][j]<<" ";
	}
	return 0;
}