#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <random>
#define int long long
#define inf 2000000000000000000
using namespace std;
mt19937 rnd(1234567890);
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,d,m,pos[100005],l0,l1,a[2][100005];
char str[100005];
struct node{
	int t,k,id;
	bool operator <(const node &x)const{
		return t<x.t;
	}
}c[100005];
struct fhq_node{
	int key,l,r,sz,val,tag;
	fhq_node(){
		key=rnd()%1000000000;
		l=r=0;
		sz=1;
		val=tag=0;
		return;
	}
}fhq[100005];
int rt;
void pushdown(int now){
	if (fhq[now].tag==0)return;
	fhq[now].val+=fhq[now].tag;
	if (fhq[now].l)fhq[fhq[now].l].tag+=fhq[now].tag;
	if (fhq[now].r)fhq[fhq[now].r].tag+=fhq[now].tag;
	fhq[now].tag=0;
	return;
}
void pushup(int now){
	fhq[now].sz=1;
	if (fhq[now].l)fhq[now].sz+=fhq[fhq[now].l].sz;
	if (fhq[now].r)fhq[now].sz+=fhq[fhq[now].r].sz;
	return;
}
int merge(int x,int y){
	if (x==0)return y;
	if (y==0)return x;
	pushdown(x),pushdown(y);
	if (fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		pushup(x);
		return x;
	}
	fhq[y].l=merge(x,fhq[y].l);
	pushup(y);
	return y;
}
void del(int &now,int k){
	pushdown(now);
	if (fhq[now].val==k){
		int l=fhq[now].l,r=fhq[now].r;
		fhq[now].l=fhq[now].r=0;
		fhq[now].sz=1;
		now=merge(l,r);
		return;
	}
	if (fhq[now].val>k)del(fhq[now].l,k);
	else del(fhq[now].r,k);
	pushup(now);
	return;
}
int kth(int now,int k){
	pushdown(now);
	if (fhq[fhq[now].l].sz+1==k)return fhq[now].val;
	if (fhq[fhq[now].l].sz>=k)return kth(fhq[now].l,k);
	return kth(fhq[now].r,k-(fhq[fhq[now].l].sz+1));
}
void split(int now,int k,int &x,int &y){
	if (now==0){
		x=y=0;
		return;
	}
	pushdown(now);
	if (fhq[fhq[now].l].sz+1<=k){
		x=now;
		split(fhq[now].r,k-(fhq[fhq[now].l].sz+1),fhq[now].r,y);
	}
	else{
		y=now;
		split(fhq[now].l,k,x,fhq[now].l);
	}
	if (x!=0)pushup(x);
	if (y!=0)pushup(y);
	return;
}
int getnum(int now,int x){
	if (now==0)return 0;
	pushdown(now);
	if (fhq[now].val<=x)return fhq[fhq[now].l].sz+1+getnum(fhq[now].r,x);
	return getnum(fhq[now].l,x);
}
int p,t;
int find0(int x){
	int l=1,r=l0,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[0][mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int find1(int x){
	int l=p+1,r=l1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[1][mid]<=x)ans=mid-p,l=mid+1;
		else r=mid-1;
	}
	ans+=getnum(rt,x);
	return ans;
}
int ask(int k){
	int l=1,r=inf,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		int num0=find0(mid);
		if (num0+find1(mid-num0)>=k)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int ans[100005];
signed main(){
	n=read(),d=read(),m=read();
	for (int i=1;i<=n;i++)pos[i]=read();
	scanf("%s",str+1);
	for (int i=1;i<=n;i++)
		if (str[i]=='0')a[0][++l0]=pos[i];
		else a[1][++l1]=pos[i]-l0;
	for (int i=1;i<=m;i++)c[i].t=read(),c[i].k=read(),c[i].id=i;
	sort(c+1,c+1+m);
	int j=1;
	p=1,t=0;
	for (int i=1;i<=l1;i++)fhq[i].val=a[1][i];
	fhq[0].sz=0;
	rt=1;
	while(j<=m){
		int qwq=(c[j].t-t)/p,awa=(c[j].t-t)%p;
		if (awa==0)qwq--,awa=p;
		if (p==l1||kth(rt,awa)+(qwq+1)*(d+p-1)<a[1][p+1]){
			fhq[rt].tag+=qwq*(d+p-1);
			int x,y;
			split(rt,awa,x,y);
			fhq[x].tag+=d+p-1;
			rt=merge(y,x);
			t=c[j].t;
		}
		else{
			int tl=0,tr=c[j].t-t,dt=0;
			while(tl<=tr){
				int mid=(tl+tr)/2;
				int _qwq=mid/p,_awa=mid%p;
				if (_awa==0)_qwq--,_awa=p;
				if (kth(rt,_awa)+(_qwq+1)*(d+p-1)>=a[1][p+1])qwq=_qwq,awa=_awa,dt=mid,tr=mid-1;
				else tl=mid+1;
			}
			fhq[rt].tag+=qwq*(d+p-1);
			int x,y;
			split(rt,awa,x,y);
			fhq[x].tag+=d+p-1;
			int id=x;
			while(fhq[id].r!=0)pushdown(id),id=fhq[id].r;
			pushdown(id);
			rt=merge(y,x);
			del(rt,fhq[id].val);
			while(p<l1&&a[1][p+1]<=fhq[id].val)rt=merge(rt,p+1),fhq[id].val++,p++;
			rt=merge(rt,id);
			t+=dt;
		}
		while(j<=m&&c[j].t==t)ans[c[j].id]=ask(c[j].k),j++;
	}
	for (int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}