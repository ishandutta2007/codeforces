#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
#define inf 1000000000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,q;
int u[500005],v[500005],w[500005],first[500005],nxt[500005];
int book[200005],dis_s[200005],dis_t[200005],id_tot,id[200005];
struct node{
	int id,pre,wid,dis;
	node(){
		id=pre=dis=0;
		return;
	}
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
node make_node(int id,int pre,int wid,int dis){
	node ans;
	ans.id=id,ans.pre=pre,ans.wid=wid,ans.dis=dis;
	return ans;
}
priority_queue<node> h;
vector<int> e[200005];
int get_wid(int qwq){
	if (qwq<=m)return qwq;
	return qwq-m;
}
void dijkstra_s(){
	memset(book,0,sizeof(book));
	memset(dis_s,0x3f,sizeof(dis_s));
	dis_s[1]=0;
	h.push(make_node(1,0,0,0));
	while(!h.empty()){
		node qwq=h.top();
		h.pop();
		int now=qwq.id;
		if (book[now]==1)continue;
		book[now]=1;
		if (qwq.pre!=0)e[qwq.pre].push_back(now);
		for (int i=first[now];i;i=nxt[i]){
			if (dis_s[v[i]]>dis_s[now]+w[i]){
				dis_s[v[i]]=dis_s[now]+w[i];
				h.push(make_node(v[i],now,get_wid(i),dis_s[v[i]]));
			}
		}
	}
	return;
}
int nxt_id[200005],nxt_wid[200005];
void dijkstra_t(){
	memset(book,0,sizeof(book));
	memset(dis_t,0x3f,sizeof(dis_t));
	dis_t[n]=0;
	h.push(make_node(n,0,0,0));
	while(!h.empty()){
		node qwq=h.top();
		h.pop();
		int now=qwq.id;
		if (book[now]==1)continue;
		book[now]=1;
		if (qwq.pre!=0)nxt_id[now]=qwq.pre,nxt_wid[now]=qwq.wid;
		for (int i=first[now];i;i=nxt[i]){
			if (dis_t[v[i]]>dis_t[now]+w[i]){
				dis_t[v[i]]=dis_t[now]+w[i];
				h.push(make_node(v[i],now,get_wid(i),dis_t[v[i]]));
			}
		}
	}
	memset(book,0,sizeof(book));
	int awa=1;
	while(awa){
		id[awa]=++id_tot;
		if (nxt_wid[awa]!=0)book[nxt_wid[awa]]=1;
		awa=nxt_id[awa];
	}
	return;
}
void dfs(int now){
	for (int i=0;i<e[now].size();i++){
		if (id[e[now][i]]==0)id[e[now][i]]=id[now];
		dfs(e[now][i]);
	}
	return;
}
struct BIT{
	int tree[200005],maxn;
	BIT(){
		memset(tree,0x3f,sizeof(tree));
		maxn=200000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]=min(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=inf;
		while(pos)ans=min(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit;
vector<int> ins_pos[200005],ins_val[200005];
vector<int> ask_id[200005],ask_pos[200005];
int ans[200005];
signed main(){
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		u[i]=read(),v[i]=read(),w[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	dijkstra_s();
	dijkstra_t();
	dfs(1);
	for (int i=1;i<=m;i++){
		int x=u[i],y=v[i];
		if (id[x]>id[y])swap(x,y);
		if (book[i]==1)continue;
		ins_pos[id[y]].push_back(id[x]);
		ins_val[id[y]].push_back(dis_s[x]+w[i]+dis_t[y]);
	}
	for (int i=1;i<=q;i++){
		int x,y;
		x=read(),y=read();
		ans[i]=min(dis_s[u[x]]+dis_t[v[x]]+y,dis_s[v[x]]+dis_t[u[x]]+y);
		if (book[x]==1){
			int a=u[x],b=v[x];
			if (id[a]>id[b])swap(a,b);
			ask_id[id[b]].push_back(i);
			ask_pos[id[b]].push_back(id[a]);
		}
		else ans[i]=min(ans[i],dis_s[n]);
	}
	for (int i=n;i>=1;i--){
		for (int j=0;j<ins_pos[i].size();j++)bit.add(ins_pos[i][j],ins_val[i][j]);
		for (int j=0;j<ask_id[i].size();j++)ans[ask_id[i][j]]=min(ans[ask_id[i][j]],bit.ask(ask_pos[i][j]));
	}
	for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}