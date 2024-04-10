#include<iostream>
using namespace std;
const int o=1e4;
int n,h[o],cnt,a[o],b[o],x,ans,md;bool vis[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		a[++cnt]=nw,b[cnt]=e[i].v,dfs(e[i].v,nw),a[++cnt]=nw,b[cnt]=e[i].v;
}
int query(int l,int r){
	int c=0;
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=l;i<=r;++i){
		if(!vis[a[i]]) vis[a[i]]=1,++c;
		if(!vis[b[i]]) vis[b[i]]=1,++c;
	}
	cout<<"? "<<c<<" ";
	for(int i=1;i<=n;++i) if(vis[i]) cout<<i<<" ";
	cout<<endl;cout.flush();cin>>c;
	return c;
}
int main(){
	cin>>n;
	for(int i=1,j,k;i<n;++i) cin>>j>>k,ad(j,k),ad(k,j);
	dfs(1,cnt=0);
	x=query(1,cnt);
	for(ans=1;ans<cnt;)
		if(query(ans,md=ans+cnt>>1)==x) cnt=md;
		else ans=md+1;
	cout<<"! "<<a[ans]<<" "<<b[ans];
	return 0;
}