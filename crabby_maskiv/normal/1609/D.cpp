#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e3+5;
int n,m;
int a[N],b[N];
int fa[N],sz[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
int mrg(int u,int v){
	u=rt(u);v=rt(v);
	if(u==v) return 1;
	fa[u]=v;
	sz[v]+=sz[u];
	return 0;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	int c=0;
	for(j=1;j<=m;j++){
		cin>>a[j]>>b[j];
		c+=mrg(a[j],b[j]);
		vector<int> x;
		for(i=1;i<=n;i++)
			if(fa[i]==i) x.push_back(sz[i]);
		sort(x.begin(),x.end(),greater<int>());
		int ans=0;
		for(i=0;i<=c;i++) ans+=x[i];
		cout<<ans-1<<endl;
	}
	return 0;
}