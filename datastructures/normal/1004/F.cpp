#include <iostream>
#include <cstdio>
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
int n,m,x,a[100005],opt,xx,yy;
struct tree_node{
	int pl,plen[21],pval[21];
	int sl,slen[21],sval[21];
	ll ans;
	tree_node(){
		pl=0;
		memset(plen,0,sizeof(plen));
		memset(pval,0,sizeof(pval));
		sl=0;
		memset(slen,0,sizeof(slen));
		memset(sval,0,sizeof(sval));
		ans=0;
		return;
	}
}tree[400005];
int pl,plen[41],pval[41];
int sl,slen[41],sval[41];
tree_node tree_merge(tree_node a,tree_node b){
	tree_node c;
	int num;
	pl=0;
	for (int i=1;i<=a.pl;i++){
		++pl;
		plen[pl]=a.plen[i];
		pval[pl]=a.pval[i];
	}
	int aval=a.pval[a.pl];
	for (int i=1;i<=b.pl;i++){
		++pl;
		plen[pl]=b.plen[i];
		pval[pl]=b.pval[i]|aval;
	}
	num=0;
	for (int i=1;i<=pl;i++){
		num+=plen[i];
		if (i==pl||pval[i]!=pval[i+1]){
			++c.pl;
			c.pval[c.pl]=pval[i];
			c.plen[c.pl]=num;
			num=0;
		}
	}
	sl=0;
	for (int i=1;i<=b.sl;i++){
		++sl;
		slen[sl]=b.slen[i];
		sval[sl]=b.sval[i];
	}
	int bval=b.sval[b.sl];
	for (int i=1;i<=a.sl;i++){
		++sl;
		slen[sl]=a.slen[i];
		sval[sl]=a.sval[i]|bval;
	}
	num=0;
	for (int i=1;i<=sl;i++){
		num+=slen[i];
		if (i==sl||sval[i]!=sval[i+1]){
			++c.sl;
			c.sval[c.sl]=sval[i];
			c.slen[c.sl]=num;
			num=0;
		}
	}
	int j=b.pl,sum=b.plen[b.pl];
	ll ans=0;
	for (int i=1;i<=a.sl;i++){
		while((a.sval[i]|b.pval[j-1])>=x&&j>1)j--,sum+=b.plen[j];
		if ((a.sval[i]|b.pval[j])>=x)ans+=1ll*a.slen[i]*sum;
	}
	c.ans=a.ans+b.ans+ans;
	return c;
}
void pushup(int now){
	tree[now]=tree_merge(tree[now*2],tree[now*2+1]);
	return;
}
void update(int now,int nowl,int nowr,int pos,int val){
	if (nowl==nowr){
		tree[now].pl=tree[now].sl=1;
		tree[now].plen[1]=tree[now].slen[1]=1;
		tree[now].pval[1]=tree[now].sval[1]=val;
		tree[now].ans=0;
		if (val>=x)tree[now].ans=1;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)update(now*2,nowl,mid,pos,val);
	else update(now*2+1,mid+1,nowr,pos,val);
	pushup(now);
	return;
}
tree_node query(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt)return tree[now];
	tree_node ans;
	int mid=(nowl+nowr)/2;
	if (mid>=lt)ans=tree_merge(ans,query(now*2,nowl,mid,lt,rt));
	if (mid+1<=rt)ans=tree_merge(ans,query(now*2+1,mid+1,nowr,lt,rt));
	return ans;
}
void build(int now,int nowl,int nowr){
	if (nowl==nowr){
		int val=a[nowl];
		tree[now].pl=tree[now].sl=1;
		tree[now].plen[1]=tree[now].slen[1]=1;
		tree[now].pval[1]=tree[now].sval[1]=val;
		if (val>=x)tree[now].ans=1;
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	pushup(now);
	return;
}
int main(){
	cin>>n>>m>>x;
	for (int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++){
		opt=read(),xx=read(),yy=read();
		if (opt==1)update(1,1,n,xx,yy);
		if (opt==2){
			tree_node qwq=query(1,1,n,xx,yy);
			printf("%lld\n",qwq.ans);
		}
	}
	return 0;
}