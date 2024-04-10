#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node1{
	int x,y,d;
	node1(){
		x=y=d=0;
		return;
	}
}c1[100005];
struct node2{
	int x,y;
	node2(){
		x=y=0;
		return;
	}
}c2[100005];
struct awa{
	int a,b,c,d,opt;//opt=0:upd  opt=1:ask
	awa(){
		a=b=c=d=0;
		opt=-1;
		return;
	}
}d[200005];//{(a0<=a1),(b0<=b1),(c0<=c1<=d0)}
bool cmp1(awa a,awa b){
	if (a.a!=b.a)return a.a<b.a;
	if (a.b!=b.b)return a.b<b.b;
	return a.opt<b.opt;
}
bool cmp2(awa a,awa b){
	if (a.b!=b.b)return a.b<b.b;
	return a.opt<b.opt;
}
int tot;
int n,m,p[100005],s[100005],b[100005],inc[100005],pref[100005];
int qwq[100005];
int ans[100005];
int larger(int x){
	int l=1,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (qwq[mid]>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int lower(int x){
	int l=1,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (qwq[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
struct BIT{
	int tree[200005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=200000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit;
void add(int l,int r,int val){
	if (l>r)return;
	bit.add(l,val);
	bit.add(r+1,-val);
	return;
}
int ask(int pos){
	return bit.ask(pos);
}
void cdq(int l,int r){
	if (l==r)return;
	int mid=(l+r)/2;
	cdq(l,mid);
	cdq(mid+1,r);
	int i=l;
	for (int j=mid+1;j<=r;j++){
		while(i<=mid&&d[i].b<=d[j].b){
			if (d[i].opt==0)add(d[i].c,d[i].d,1);
			i++;
		}
		if (d[j].opt==1)ans[d[j].d]+=ask(d[j].c);
	}
	for (int k=l;k<i;k++)
		if (d[k].opt==0)add(d[k].c,d[k].d,-1);
	sort(d+l,d+r+1,cmp2);
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)scanf("%d",&s[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	for (int i=1;i<=m;i++)scanf("%d",&inc[i]);
	for (int i=1;i<=m;i++)scanf("%d",&pref[i]);
	for (int i=1;i<=n;i++)c1[i].x=p[i],c1[i].y=b[i],c1[i].d=s[i]-p[i];
	for (int i=1;i<=m;i++)c2[i].x=inc[i],c2[i].y=pref[i];
	for (int i=1;i<=n;i++){
		++tot;
		d[tot].a=c1[i].x+c1[i].y,d[tot].b=c1[i].x-c1[i].y;
		d[tot].c=c1[i].x,d[tot].d=c1[i].x+c1[i].d;
		d[tot].opt=0; 
	}
	for (int i=1;i<=m;i++){
		++tot;
		d[tot].a=c2[i].x+c2[i].y,d[tot].b=c2[i].x-c2[i].y;
		d[tot].c=c2[i].x,d[tot].d=i;
		d[tot].opt=1;
		qwq[i]=c2[i].x;
	}
	sort(qwq+1,qwq+1+m);
	for (int i=1;i<=tot;i++)
		if (d[i].opt==0)d[i].c=larger(d[i].c),d[i].d=lower(d[i].d);
		else d[i].c=lower(d[i].c);
	sort(d+1,d+1+tot,cmp1);
	cdq(1,tot);
	for (int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}