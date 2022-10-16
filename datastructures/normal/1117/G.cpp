#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void out(ll x){
	if (x==0)return;
	out(x/10);
	putchar('0'+x%10);
	return;
}
void write(ll x){
	if (x==0)putchar('0');
	else out(x);
	putchar(' ');
	return; 
}
int n,q,p[1000005],l[1000005],r[1000005];
int pre[1000005];
ll ans[1000005];
vector<int> ql[1000005],qid[1000005];
struct SGT{
	ll tree[4000005],tag[4000005];
	void mem(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	void pushdown(int now,int nowl,int nowr){
		int mid=(nowl+nowr)/2;
		tree[now*2]+=tag[now]*(mid-nowl+1),tree[now*2+1]+=tag[now]*(nowr-mid);
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	void pushup(int now){
		tree[now]=tree[now*2]+tree[now*2+1];
		return;
	}
	void tree_update(int now,int nowl,int nowr,int lt,int rt,ll val){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=(nowr-nowl+1)*val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	void update(int l,int r,ll val){
		tree_update(1,1,n,l,r,val);
		return;
	}
	ll tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2;
		ll s=0;
		if (mid>=lt)s+=tree_query(now*2,nowl,mid,lt,rt);
		if (mid+1<=rt)s+=tree_query(now*2+1,mid+1,nowr,lt,rt);
		return s;
	}
	ll query(int l,int r){
		return tree_query(1,1,n,l,r);
	}
}sgt;
int que[1000005],tail;
void work(){
	tail=0;
	for (int i=1;i<=n;i++){
		while(tail&&p[que[tail]]<=p[i])tail--;
		pre[i]=que[tail]+1;
		que[++tail]=i;
	}
	for (int i=1;i<=n;i++)ql[i].clear(),qid[i].clear();
	for (int i=1;i<=q;i++)ql[r[i]].push_back(l[i]),qid[r[i]].push_back(i);
	sgt.mem();
	for (int i=1;i<=n;i++){
		sgt.update(pre[i],i,1);
		for (int j=0,len=ql[i].size();j<len;j++)
			ans[qid[i][j]]+=sgt.query(ql[i][j],i);
	}
	sgt.mem();
	return;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)p[i]=read();
	for (int i=1;i<=q;i++)l[i]=read();
	for (int i=1;i<=q;i++)r[i]=read();
	work();
	for (int i=1;i<=n/2;i++)swap(p[i],p[n-i+1]);
	for (int i=1;i<=q;i++)l[i]=n-l[i]+1,r[i]=n-r[i]+1,swap(l[i],r[i]);
	work();
	for (int i=1;i<=q;i++)ans[i]-=(r[i]-l[i]+1),write(ans[i]);
	return 0;
}