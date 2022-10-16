#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;
const int w=20;
struct node{
	int l,r,c,t0,t1,sz;
	node(){
		l=r=c=t0=sz=0;
		t1=(1<<w)-1;
		return;
	}
}tree[15000005];
int cnt;
void pushdown(int now,int d){
	if (tree[now].t0==0&&tree[now].t1==(1<<w)-1)return;
	if ((tree[now].t0&(1<<d))!=0&&(tree[now].t1&(1<<d))==0)swap(tree[now].l,tree[now].r);
	else{
		if ((tree[now].t0&(1<<d))!=0&&tree[now].l!=0)tree[now].r=tree[now].l,tree[now].l=0;
		if ((tree[now].t1&(1<<d))==0&&tree[now].r!=0)tree[now].l=tree[now].r,tree[now].r=0;
	}
	if (tree[now].l!=0){
		int v=tree[now].l;
		for (int i=0;i<w;i++){
			if ((tree[v].t0&(1<<i))==0)tree[v].t0|=(tree[now].t0&(1<<i));
			else tree[v].t0^=(1<<i),tree[v].t0|=(tree[now].t1&(1<<i));
			if ((tree[v].t1&(1<<i))==0)tree[v].t1|=(tree[now].t0&(1<<i));
			else tree[v].t1^=(1<<i),tree[v].t1|=(tree[now].t1&(1<<i));
		}
	}
	if (tree[now].r!=0){
		int v=tree[now].r;
		for (int i=0;i<w;i++){
			if ((tree[v].t0&(1<<i))==0)tree[v].t0|=(tree[now].t0&(1<<i));
			else tree[v].t0^=(1<<i),tree[v].t0|=(tree[now].t1&(1<<i));
			if ((tree[v].t1&(1<<i))==0)tree[v].t1|=(tree[now].t0&(1<<i));
			else tree[v].t1^=(1<<i),tree[v].t1|=(tree[now].t1&(1<<i));
		}
	}
	tree[now].t0=0,tree[now].t1=(1<<w)-1;
	return;
}
void pushup(int now,int d){
	tree[now].c=tree[now].sz=0;
	if (tree[now].l!=0)tree[now].c|=tree[tree[now].l].c,tree[now].sz+=tree[tree[now].l].sz;
	if (tree[now].r!=0)tree[now].c|=tree[tree[now].r].c,tree[now].sz+=tree[tree[now].r].sz;
	if (tree[now].l!=0&&tree[now].r!=0)tree[now].c|=(1<<d);
	return;
}
int n,q,a[200005],opt,l,r,x;
int rt;
void add(int &now,int nowl,int nowr,int d,int pos){
	if (now==0)now=++cnt;
	tree[now].sz++;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)add(tree[now].l,nowl,mid,d-1,pos);
	else add(tree[now].r,mid+1,nowr,d-1,pos);
	pushup(now,d);
	return;
}
int ask(int now,int nowl,int nowr,int d,int lt,int rt){
	if (nowl!=nowr)pushdown(now,d);
	if (nowl>=lt&&nowr<=rt)return tree[now].sz;
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt&&tree[now].l!=0)s+=ask(tree[now].l,nowl,mid,d-1,lt,rt);
	if (mid+1<=rt&&tree[now].r!=0)s+=ask(tree[now].r,mid+1,nowr,d-1,lt,rt);
	return s;
}
int tot,id[105],vl[105],vr[105],val[105],dep[105];
void find(int now,int nowl,int nowr,int d,int lt,int rt){
	if (nowl!=nowr)pushdown(now,d);
	if (nowl>=lt&&nowr<=rt){
		++tot;
		id[tot]=now;
		vl[tot]=nowl,vr[tot]=nowr;
		val[tot]=nowl;
		dep[tot]=d;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt&&tree[now].l!=0){
		find(tree[now].l,nowl,mid,d-1,lt,rt);
		if (nowl>=lt&&mid<=rt)tree[now].l=0;
	}
	if (mid+1<=rt&&tree[now].r!=0){
		find(tree[now].r,mid+1,nowr,d-1,lt,rt);
		if (mid+1>=lt&&nowr<=rt)tree[now].r=0;
	}
	pushup(now,d);
	return;
}
int merge(int x,int y,int d,int nowl,int nowr){
	if (x==0)return y;
	if (y==0)return x;
	if (nowl!=nowr)pushdown(x,d),pushdown(y,d);
	if (nowl==nowr){
		tree[x].sz=1;
		return x;
	}
	int mid=(nowl+nowr)/2;
	tree[x].l=merge(tree[x].l,tree[y].l,d-1,nowl,mid);
	tree[x].r=merge(tree[x].r,tree[y].r,d-1,mid+1,nowr);
	pushup(x,d);
	return x;
}
void work1(int now,int nowl,int nowr,int d,int t){
	if (nowl!=nowr)pushdown(now,d);
	if (!(tree[now].c&(1<<t)))return;
	int mid=(nowl+nowr)/2;
	if (d==t){
		tree[now].l=merge(tree[now].l,tree[now].r,d-1,nowl,mid);
		tree[now].r=0;
		pushup(now,d);
		return;
	}
	if (tree[now].l!=0)work1(tree[now].l,nowl,mid,d-1,t);
	if (tree[now].r!=0)work1(tree[now].r,mid+1,nowr,d-1,t);
	pushup(now,d);
	return;
}
void work2(int now,int nowl,int nowr,int d,int t){
	if (nowl!=nowr)pushdown(now,d);
	if (!(tree[now].c&(1<<t)))return;
	int mid=(nowl+nowr)/2;
	if (d==t){
		tree[now].r=merge(tree[now].r,tree[now].l,d-1,mid+1,nowr);
		tree[now].l=0;
		pushup(now,d);
		return;
	}
	if (tree[now].l!=0)work2(tree[now].l,nowl,mid,d-1,t);
	if (tree[now].r!=0)work2(tree[now].r,mid+1,nowr,d-1,t);
	pushup(now,d);
	return;
}
void ins(int &now,int nowl,int nowr,int d,int pos,int _d,int x){
	if (nowl!=nowr)pushdown(now,d);
	if (d==_d){
		now=merge(now,x,d,nowl,nowr);
		return;
	}
	if (now==0)now=++cnt;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)ins(tree[now].l,nowl,mid,d-1,pos,_d,x);
	else ins(tree[now].r,mid+1,nowr,d-1,pos,_d,x);
	pushup(now,d);
	return;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		if (i==1||a[i]!=a[i-1])add(rt,0,(1<<w)-1,19,a[i]);
	while(q--){
		scanf("%d",&opt);
		if (opt<=3){
			scanf("%d%d%d",&l,&r,&x);
			tot=0;
			find(rt,0,(1<<w)-1,19,l,r);
		}
		if (opt==1){
			for (int i=1;i<=tot;i++){
				val[i]&=x;
				for (int j=0;j<w;j++)
					if (!(x&(1<<j))){
						work1(id[i],vl[i],vr[i],dep[i],j);
						if (tree[id[i]].t0&(1<<j))tree[id[i]].t0^=(1<<j);
						if (tree[id[i]].t1&(1<<j))tree[id[i]].t1^=(1<<j);
					}
			}
		}
		if (opt==2){
			for (int i=1;i<=tot;i++){
				val[i]|=x;
				for (int j=0;j<w;j++){
					if (x&(1<<j)){
						work2(id[i],vl[i],vr[i],dep[i],j);
						if (!(tree[id[i]].t0&(1<<j)))tree[id[i]].t0^=(1<<j);
						if (!(tree[id[i]].t1&(1<<j)))tree[id[i]].t1^=(1<<j);
					}
				}
			}
		}
		if (opt==3){
			for (int i=1;i<=tot;i++){
				val[i]^=x;
				for (int j=dep[i];j>=0;j--){
					if (!(x&(1<<j)))continue;
					tree[id[i]].t0^=(1<<j);
					tree[id[i]].t1^=(1<<j);
				}
			}
		}
		if (opt<=3){
			for (int i=1;i<=tot;i++)
				ins(rt,0,(1<<w)-1,19,val[i],dep[i],id[i]);
		}
		if (opt==4){
			scanf("%d%d",&l,&r);
			printf("%d\n",ask(rt,0,(1<<w)-1,19,l,r));
		}
	}
	return 0;
}