#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int n,d[o],h[o],cnt,f[o],g[o],a,b,res,id[o];vector<pair<int,int> > sn[o];vector<int> ans,yny,pm[o],sm[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw,int fa){
	d[nw]=d[fa]+1;f[nw]=0;sn[nw].clear();
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		Dfs(e[i].v,nw),sn[nw].push_back(make_pair(f[e[i].v],e[i].v));
	sort(sn[nw].begin(),sn[nw].end());pm[nw].resize(sn[nw].size());sm[nw].resize(sn[nw].size());
	for(int i=sn[nw].size()-1,j=0;i+1;--i,++j)
		sm[nw][i]=f[nw]=max(f[nw],sn[nw][i].first+j),id[sn[nw][i].second]=i;
	for(int i=0,j=sn[nw].size(),t=0;i<j;++i) pm[nw][i]=t=max(t,sn[nw][i].first+j-i-1);
}
void dfs(int nw,int fa){
	int l=0,r=sn[nw].size(),md;
	if(fa<2) g[nw]=max(g[nw],max(id[nw]?pm[fa][id[nw]-1]-1:0,(id[nw]<sn[fa].size()-1)?sm[fa][id[nw]+1]:0));
	for(;l<r;) if(sn[nw][(md=(l+r>>1)+1)-1].first<g[nw]) l=md;else r=md-1;
	yny.clear();yny.push_back(g[nw]);
	for(int i=sn[nw].size()-1;i+1;--i) yny.push_back(sn[nw][i].first);
	sort(yny.begin(),yny.end());
	for(int i=yny.size()-1,j=1,mx=0;i+1;--i,++j) ans[nw-1]=max(ans[nw-1],mx+yny[i]+j),mx=max(mx,yny[i]);
	for(int i=l-1,j=sn[nw].size(),mx=(g[nw]+j-l);i+1;dfs(sn[nw][i--].second,nw))
		g[sn[nw][i].second]=max(mx,max(i?pm[nw][i-1]:0,l<j?sm[nw][l]:0)),mx=max(mx,sn[nw][i].first+j-i);
	for(int i=l,j=sn[nw].size(),mx=(g[nw]+j-l-1);i<j;dfs(sn[nw][i++].second,nw))
		g[sn[nw][i].second]=max(mx,max(l?pm[nw][l-1]:0,i<j-1?sm[nw][i+1]:0)),mx=max(mx,sn[nw][i].first+j-i-2);
}
inline int query(int x){cout<<"? "<<x<<endl;cout.flush();int yny;cin>>yny;return yny;}
void slv(int nw,int fa){
	sn[nw].clear();
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) sn[nw].push_back(make_pair(f[e[i].v],e[i].v));
	sort(sn[nw].begin(),sn[nw].end());
	for(int i=sn[nw].size()-1;i+1;--i){
		slv(sn[nw][i].second,nw);
		if(b||d[res]<d[nw]||(d[res]>d[nw]&&fa)) return;
	}
	if(sn[nw].empty()) res=query(nw);
	if(d[res]<d[nw]) return;
	if(!a) a=nw;else b=nw;
}
int main(){
	cin>>n;ans.resize(n);
	if(n==1){cout<<"0"<<endl,cout.flush(),cout<<"! 1 1"<<endl,cout.flush();return 0;}
	for(int i=n,u,v;--i;ad(u,v),ad(v,u)) cin>>u>>v;
	Dfs(1,0);
	for(int i=sn[1].size()-1,j=1,mx=0;i+1;--i,++j)
		ans[0]=max(ans[0],mx+sn[1][i].first+j),mx=max(mx,sn[1][i].first);
	for(int i=h[1];i;i=e[i].p) dfs(e[i].v,1);
	int opt=0;
	for(int i=0;i<n;++i) opt=max(opt,ans[i]);
	cout<<opt<<endl;cout.flush();
	int x;
	cin>>x;Dfs(x,0);slv(x,a=b=0);if(!b) b=a;cout<<"! "<<a<<" "<<b<<endl;cout.flush();
	return 0;
}