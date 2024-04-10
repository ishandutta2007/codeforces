#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#define ll long long
#define inf 1000000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
mt19937 rnd(time(NULL));
struct fhq_node{
	int l,r,key,val,sz;
	ll sum;
}fhq[1000005];
int fhq_cnt,root[250005];
fhq_node make_node(int val){
	fhq_node ans;
	ans.l=ans.r=0;
	ans.key=rnd()%1000000000;
	ans.sum=ans.val=val;
	ans.sz=1;
	return ans;
}
void pushup(int now){
	fhq[now].sz=fhq[fhq[now].l].sz+fhq[fhq[now].r].sz+1;
	fhq[now].sum=fhq[fhq[now].l].sum+fhq[fhq[now].r].sum+fhq[now].val;
	return;
}
void split(int now,int val,int &x,int &y){
	if (now==0){
		x=y=0;
		return;
	}
	if (fhq[now].val<=val){
		x=now;
		split(fhq[now].r,val,fhq[now].r,y);
		pushup(x);
	}
	else{
		y=now;
		split(fhq[now].l,val,x,fhq[now].l);
		pushup(y);
	}
	return;
}
int merge(int x,int y){
	if (x==0)return y;
	if (y==0)return x;
	if (fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		pushup(x);
		return x;
	}
	else{
		fhq[y].l=merge(x,fhq[y].l);
		pushup(y);
		return y;
	}
	return 0;
}
ll ask(int x,int k){
	ll sum=0;
	int now=root[x];
	if (k<=0)return 0;
	if (k>fhq[now].sz)return inf;
	while(now){
		if (fhq[fhq[now].l].sz>=k)now=fhq[now].l;
		if (fhq[fhq[now].l].sz+1==k){
			sum+=fhq[fhq[now].l].sum+fhq[now].val;
			break;
		}
		if (fhq[fhq[now].l].sz+1<k){
			sum+=fhq[fhq[now].l].sum+fhq[now].val;
			k-=(fhq[fhq[now].l].sz+1);
			now=fhq[now].r;
		}
	}
	return sum;
}
void ins(int now,int val){
	fhq[++fhq_cnt]=make_node(val);
	int x,y;
	split(root[now],val,x,y);
	root[now]=merge(merge(x,fhq_cnt),y);
	return;
}
void del(int now,int val){
	int x,y,z;
	split(root[now],val-1,x,y);
	split(y,val,y,z);
	y=merge(fhq[y].l,fhq[y].r);
	root[now]=merge(x,merge(y,z));
	return;
}
int n,u[500005],v[500005],w[500005],first[250005],nxt[500005];
vector<int> e[250005],ew[250005];
int du[250005];
vector<int> ins_pos[250005];
ll ans[250005];
int book[250005],c[250005],tot;
ll f[250005][2],x;
ll d[250005];
int len;
int vis[250005];
void dfs(int now,int fa,ll qwq){
	vis[now]=1;
	for (int i=0;i<e[now].size();i++){
		if (e[now][i]==fa)continue;
		dfs(e[now][i],now,ew[now][i]);
	}
	f[now][0]=0;
	f[now][1]=qwq;
	len=0;
	int d0=du[now]-x;
	int d1=du[now]-x-1;
	ll sf=0;
	for (int i=0;i<e[now].size();i++){
		if (e[now][i]==fa)continue;
		if (f[e[now][i]][1]<=f[e[now][i]][0])sf+=f[e[now][i]][1],d0--,d1--;
		else sf+=f[e[now][i]][0],d[++len]=f[e[now][i]][1]-f[e[now][i]][0];
	}
	sort(d+1,d+1+len);
	ll sd=0;
	f[now][0]=sf+ask(now,d0);
	f[now][1]=sf+ask(now,d1);
	for (int i=1;i<=len;i++){
		sd+=d[i];
		f[now][0]=min(f[now][0],sf+sd+ask(now,d0-i));
		f[now][1]=min(f[now][1],sf+sd+ask(now,d1-i));
	}
	f[now][1]+=qwq;
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read(),w[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		ins(u[i],w[i]);
		ins(v[i],w[i]);
		du[u[i]]++;
		du[v[i]]++;
	}
	for (int i=1;i<=n;i++)ins_pos[du[i]].push_back(i);
	for (int i=n;i>=2;i--){
		for (int j=0;j<ins_pos[i].size();j++){
			int now=ins_pos[i][j];
			for (int k=first[now];k;k=nxt[k])
				if (book[v[k]]==1){
					e[v[k]].push_back(now);
					ew[v[k]].push_back(w[k]);
					e[now].push_back(v[k]);
					ew[now].push_back(w[k]);
					del(v[k],w[k]);
					del(now,w[k]);
				}
			book[now]=1;
			c[++tot]=now;
		}
		x=i-1;
		for (int j=1;j<=tot;j++)vis[c[j]]=0;
		for (int j=1;j<=tot;j++)
			if (vis[c[j]]==0){
				dfs(c[j],0,inf);
				ans[i]+=f[c[j]][0];
			}
	}
	for (int i=1;i<n;i++)ans[1]+=w[i];
	for (int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}