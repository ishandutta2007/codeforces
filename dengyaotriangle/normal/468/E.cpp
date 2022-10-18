#include<bits/stdc++.h>

using namespace std;

const int maxn=200;
const int maxw=100005;
const int mdn=1000000007;

int n,k;
struct p{
	int x,y,z;
}pt[maxn];

bool vis[maxn];
int vist[maxn],c2;
vector<pair<int,int> > adj[maxn];
int deg[maxn];
void dfs0(int u){
	vist[u]=c2;
	deg[u]=0;
	for(int i=0;i<(int)adj[u].size();i++){
		int v=adj[u][i].first;
		deg[u]+=!vis[v];
		if(!vis[v]&&vist[v]!=c2){
			dfs0(v);
		}
	}
}

int visw[maxn],c3;

int tsiz,tdeg,mdeg,mdx,mdi,rfx,rfi;

void dfs1(int u,int fa){
	visw[u]=c3;
	tdeg+=deg[u];tsiz++;
	for(int i=0;i<(int)adj[u].size();i++){
		int v=adj[u][i].first;
		if(!vis[v]){
			if(visw[v]!=c3){
				int cur=deg[u]+deg[v];
				if(cur>mdeg)mdeg=cur,mdx=u,mdi=i;
				dfs1(v,u);
			}else if(v==fa){
				rfx=u;rfi=i;
			}
		}
	}
}

int csz;
int fac[maxw];

typedef vector<int> poly;

poly operator+(const poly&a,const poly&b){
	poly c=a;
	if(b.size()>a.size())c.resize(b.size());
	for(int i=0;i<(int)b.size();i++)c[i]=(c[i]+b[i])%mdn;
	return c;
}
poly operator*(const poly&a,const poly&b){
	if(a.empty())return a;
	if(b.empty())return b;
	poly c;c.resize(a.size()+b.size()-1);
	for(int i=0;i<(int)a.size();i++){
		for(int j=0;j<(int)b.size();j++){
			c[i+j]=(c[i+j]+a[i]*(long long)b[j])%mdn;
		}
	}
	return c;
}
poly operator*(const poly&a,int b){
	poly c=a;
	for(int i=0;i<(int)a.size();i++)c[i]=c[i]*(long long)b%mdn;
	return c;
}
pair<poly,poly> dfs2(int u,int fa){
	pair<poly,poly> p0;
	p0.first.push_back(1);
	for(int i=0;i<(int)adj[u].size();i++){
		int v=adj[u][i].first,w=adj[u][i].second;
		if(!vis[v]&&v!=fa){
			pair<poly,poly> p1=dfs2(v,u);
			
			poly p2=p0.first*p1.first*w;
			p2.insert(p2.begin(),0);
			
			poly pt=p1.first+p1.second;
			
			p0.first=p0.first*pt;
			p0.second=p0.second*pt+p2;
		}
	}
	return p0;
}

poly work(int u){
	//cerr<<u<<endl;
	++c3;tdeg=tsiz=0,mdeg=-1;
	dfs1(u,0);
	if(tdeg/2==tsiz-1){
		//cerr<<"!"<<u<<' '<<tsiz<<endl;
		pair<poly,poly> res=dfs2(u,0);
		return res.first+res.second;
	}
	int cu,ci,cv;
	if(tdeg/2==tsiz)cu=rfx,ci=rfi;
	else cu=mdx,ci=mdi;
	cv=adj[cu][ci].first;
	//cerr<<cu<<' '<<cv<<endl;
	//choose
	vis[cu]=1;vis[cv]=1;
	csz--;
	poly ans(1,adj[cu][ci].second);
	vector<int> ch;
	c2++;
	for(int i=0;i<(int)adj[cu].size();i++){
		int v=adj[cu][i].first;
		if(!vis[v]&&vist[v]!=c2){
			dfs0(v);
			ch.push_back(v);
		}
	}
	for(int i=0;i<(int)adj[cv].size();i++){
		int v=adj[cv][i].first;
		if(!vis[v]&&vist[v]!=c2){
			dfs0(v);
			ch.push_back(v);
		}
	}
	for(int i=0;i<(int)ch.size();i++){
		//cerr<<u<<"->"<<ch[i]<<endl;
		ans=ans*work(ch[i]);
	}
	ans.insert(ans.begin(),0);
	csz++;
	vis[cu]=0;vis[cv]=0;
	
	
	//not choose
	int vi=0;
	for(int i=0;i<(int)adj[cv].size();i++){
		if(adj[cv][i].first==cu)vi=i;
	}
	pair<int,int> ue=adj[cu][ci],ve=adj[cv][vi];
	adj[cu].erase(adj[cu].begin()+ci);
	adj[cv].erase(adj[cv].begin()+vi);
	poly cans(1,1);
	ch.clear();c2++;
	if(!vis[cu]&&vist[cu]!=c2){
		dfs0(cu);
		ch.push_back(cu);
	}
	if(!vis[cv]&&vist[cv]!=c2){
		dfs0(cv);
		ch.push_back(cv);
	}
	for(int i=0;i<(int)ch.size();i++){
		cans=cans*work(ch[i]);
	}
	adj[cu].insert(adj[cu].begin()+ci,ue);
	adj[cv].insert(adj[cv].begin()+vi,ve);
	//cerr<<">"<<u<<endl;
	return ans+cans;
}

int main(){
	scanf("%d%d",&n,&k);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*(long long)i%mdn;
	map<int,int> mx,my;
	for(int i=1;i<=k;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(!mx.count(x)){
			int u=mx.size()+1;
			mx[x]=u;
		}
		if(!my.count(y)){
			int u=my.size()+1;
			my[y]=u;
		}
		x=mx[x],y=my[y];
		adj[x].push_back(make_pair(y+k,(mdn+z-1)%mdn));
		adj[y+k].push_back(make_pair(x,(mdn+z-1)%mdn));
	}
	csz=n;
	vector<int> ch;
	c2++;
	for(int i=1;i<=(int)mx.size();i++){
		if(vist[i]!=c2){
			dfs0(i);
			ch.push_back(i);
		}
	}
	poly cans(1,1);
	for(int i=0;i<(int)ch.size();i++){
		cans=cans*work(ch[i]);
	}
	int wans=0;
	for(int i=0;i<(int)cans.size();i++)wans=(wans+cans[i]*(long long)fac[n-i])%mdn;//,cerr<<cans[i]<<endl;
	printf("%d",wans);
	return 0;
}