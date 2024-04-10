#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
const int inf=1.01e9;
int a[maxn];

struct node{
	int v1,v2;
	node* c[2];
};
node pool[maxn*4*10];
int ps;


void pu(node* rt){
	if(rt->c[0]){
		int q[4];q[0]=rt->c[0]->v1;q[1]=rt->c[0]->v2;q[2]=rt->c[1]->v1;q[3]=rt->c[1]->v2;
		if(q[0]>q[1])swap(q[0],q[1]);
		if(q[1]>q[2])swap(q[1],q[2]);
		if(q[2]>q[3])swap(q[2],q[3]);
		if(q[0]>q[1])swap(q[0],q[1]);
		if(q[1]>q[2])swap(q[1],q[2]);
		if(q[0]>q[1])swap(q[0],q[1]);
		rt->v1=q[0];
		rt->v2=q[1];
	}
}

node* bt(int l,int r){
	node* nw=pool+ps++;
	nw->v1=nw->v2=inf;
	if(l==r){
		nw->c[0]=nw->c[1]=NULL;
	}else{
		nw->c[0]=bt(l,(l+r)>>1);
		nw->c[1]=bt(((l+r)>>1)+1,r);
	}
	return nw;
}
void chg(node* rt,int cl,int cr,int i,int v){
	if(cl==cr){
		rt->v1=v;
		rt->v2=inf;
		return;
	}
	int cm=(cl+cr)>>1;
	if(i<=cm)chg(rt->c[0],cl,cm,i,v);
	else chg(rt->c[1],cm+1,cr,i,v);
	pu(rt);
}

node qry(node* rt,int cl,int cr,int l,int r){
	if(cl==l&&cr==r){
		return (*rt);
	}
	int cm=(cl+cr)>>1;
	if(r<=cm) return qry(rt->c[0],cl,cm,l,r);
	else if(l>cm) return qry(rt->c[1],cm+1,cr,l,r);
	else{
		node f1=qry(rt->c[0],cl,cm,l,cm),f2=qry(rt->c[1],cm+1,cr,cm+1,r);
		node f3;f3.c[0]=(&f1);f3.c[1]=(&f2);
		pu(&f3);return f3;
	}
}

node* rt[10];
int n;

int main(){
	int m;
	scanf("%d%d",&n,&m);
	//n=m=200005;
	for(int g=0;g<10;g++) rt[g]=bt(1,n);
	double t=time(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//a[i]=rand();
		int q=a[i];
		for(int g=0;g<10;g++){
			if(q%10) chg(rt[g],1,n,i,a[i]);
			q/=10;
		}
	}
	while(m--){
		int op;scanf("%d",&op);
		if(op==1){
			int i,x;
			scanf("%d%d",&i,&x);
			//i=rand()%n+1;x=rand();
			a[i]=x;
			int q=a[i];
			for(int g=0;g<10;g++){
				if(q%10) chg(rt[g],1,n,i,a[i]);
				else chg(rt[g],1,n,i,inf);
				q/=10;
			}
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			//l=rand()%n+1;r=rand()%n+1;if(r<l)swap(l,r);
			int an=-1;
			for(int g=0;g<10;g++){
				node ans=qry(rt[g],1,n,l,r);
				if(ans.v1==inf||ans.v2==inf) continue;
				int a=ans.v1+ans.v2;
				if(a<an||an==-1) an=a;
			}
			printf("%d\n",an);
		}
	}
	//cout<<(double)time(0)-(double)t;
    return 0;
}