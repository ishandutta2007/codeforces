#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct node{
	int s,a;
	bool operator <(const node &x)const{
		if (a!=x.a)return a<x.a;
		return s<x.s;
	}
}c[500005];
int n,d,qwq[1000005],tot;
int maxn=1100000;
struct tree_node{
	int l,r,val;
}tree[20000005];
int tree_cnt,root[500005];
void ins(int &now,int nowl,int nowr,int pos){
	int pre=now;
	now=++tree_cnt;
	tree[now]=tree[pre];
	tree[now].val++;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)ins(tree[now].l,nowl,mid,pos);
	else ins(tree[now].r,mid+1,nowr,pos);
	return;
}
int ask(int now,int nowl,int nowr,int lt,int rt){
	if (now==0)return 0;
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt)s+=ask(tree[now].l,nowl,mid,lt,rt);
	if (mid+1<=rt)s+=ask(tree[now].r,mid+1,nowr,lt,rt);
	return s;
}
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (qwq[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int find(int pos){
	if (c[pos].s<d)return -1;
	int l=1,r=pos-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (c[mid].a<=c[pos].s)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int f[500005];
int main(){
	cin>>n>>d;
	for (int i=1;i<=n;i++)c[i].s=read(),c[i].a=read(),qwq[++tot]=c[i].s,qwq[++tot]=c[i].a;
	qwq[++tot]=d;
	sort(qwq+1,qwq+1+tot);
	for (int i=1;i<=n;i++)c[i].s=lower(c[i].s),c[i].a=lower(c[i].a);
	sort(c+1,c+1+n);
	d=lower(d);
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		root[i]=root[i-1];
		ins(root[i],1,maxn,c[i].s);
		int pos=find(i);
		if (pos==-1)continue;
		f[i]=max(f[i],f[pos]+ask(root[i-1],1,maxn,c[i].a,maxn)-ask(root[pos],1,maxn,c[i].a,maxn)+1);
	}
	cout<<f[n]<<endl;
	return 0;
}
//qwq