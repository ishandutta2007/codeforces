#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,sz[200005],rt;
vector<pii>g[200005];
ll ans;
void dfs(int x,int fa){
	int tmp=0;
	sz[x]=1;
	for(int i=0;i<g[x].size();i++)if(g[x][i].fi!=fa){
		dfs(g[x][i].fi,x),sz[x]+=sz[g[x][i].fi];
		tmp=max(tmp,sz[g[x][i].fi]);
	}
	tmp=max(tmp,n-sz[x]);
	if(tmp<=n/2)rt=x;
}
int cmp[200005];
void getans(int x,int fa,ll d,int r){
	ans+=d*2,cmp[x]=r;
	for(int i=0;i<g[x].size();i++)if(g[x][i].fi!=fa)
		getans(g[x][i].fi,x,d+g[x][i].se,r);
}
priority_queue<int,vector<int>,greater<int> >arr[200005];
struct Data{
	int num,id;
	Data(int num=0,int id=0):num(num),id(id){}
	bool operator <(const Data &o)const{
		if(num!=o.num)return num<o.num;
		return id<o.id;
	}
}info[200005];
struct Node{
	int mn,id;
	Node(int mn=0,int id=0):mn(mn),id(id){}
	bool operator <(const Node &o)const{
		if(mn!=o.mn)return mn<o.mn;
		return id<o.id;
	}
}wn[200005];
set<Data>st;
set<Node>sr;
int lev=0;
void add(int x,int y){
	printf("%d ", wn[y].mn);
	sr.erase(wn[y]),arr[y].pop();
	if(!arr[y].empty()){
		wn[y]=Node(arr[y].top(),y);
		sr.insert(wn[y]);
	}
	st.erase(info[cmp[x]]);
	st.erase(info[y]);
	lev++;
	info[cmp[x]].num++,info[y].num++;
	st.insert(info[cmp[x]]);
	st.insert(info[y]);
}
int main(){
	scanf("%d",&n);
	if(n==1)return puts("0\n1"),0;
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w}),g[v].push_back({u,w});
	}
	dfs(1,0);
	cmp[rt]=rt,info[rt]={n*4,rt};
	for(auto y:g[rt])info[y.fi]={n,y.fi},getans(y.fi,rt,y.se,y.fi);
	for(int i=1;i<=n;i++)arr[cmp[i]].push(i),info[cmp[i]].num-=2;
	for(int i=1;i<=n;i++)if(cmp[i]==i){
		wn[i]={arr[i].top(),i};
		st.insert(info[i]),sr.insert(wn[i]);
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		auto it=st.begin();
		if((it->id)==cmp[i])it++;
		int t=(it->num)-lev;
		if(t-1<0){
			add(i,(it->id));
			continue;
		}
		auto it1=sr.begin();
		if((it1->id)==cmp[i]&&cmp[i]!=rt)it1++;
		add(i,(it1->id));
	}
}