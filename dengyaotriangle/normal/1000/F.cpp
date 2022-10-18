#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;

const int maxn=500005;

struct node{
	int v;
	int i;
	node* c[2];
};

int prv[maxn],lo[maxn];
node* rt[maxn];

node* nwnode(int l,int r){
	node* nw=new node;
	nw->v=0x3fff3fff;nw->c[0]=nw->c[1]=NULL;
	return nw;
}

node* cpnode(node* rt){
	node* nw=new node;
	nw->v=rt->v;nw->i=rt->i;nw->c[0]=rt->c[0];nw->c[1]=rt->c[1];
	return nw;
}

void pu(node* rt){
	if(!rt) return;
	if(!rt->c[0]) return;
	if(rt->c[0]->v<rt->c[1]->v ){
		rt->v=rt->c[0]->v;
		rt->i=rt->c[0]->i;
	}else{
		rt->v=rt->c[1]->v;
		rt->i=rt->c[1]->i;
	}	
}

node* bt(int l,int r){
	node* nw=nwnode(l,r);
	if(l!=r){
		nw->c[0]=bt(l,(l+r)/2);
		nw->c[1]=bt((l+r)/2+1,r);
	}
	return nw;
}

node* chg(node* rt,int i,int v,int cl,int cr,int ik){
	int cm=(cl+cr)/2;
	node* nw=cpnode(rt);
	if(cl==cr){
		nw->v=v;
		nw->i=ik;
	}else if(i<=cm) nw->c[0]=chg(nw->c[0],i,v,cl,cm,ik);
	else nw->c[1]=chg(nw->c[1],i,v,cm+1,cr,ik);
	pu(nw);
	return nw;
}

pair<int,int> qry(node* rt,int l,int r,int cl,int cr){
	int cm=(cl+cr)/2;
	if(cl==l&&cr==r) return make_pair(rt->v,rt->i);
	else if(r<=cm) return qry(rt->c[0],l,r,cl,cm);
	else if(l>cm) return qry(rt->c[1],l,r,cm+1,cr);
	else{
		pair<int,int> p1=qry(rt->c[0],l,cm,cl,cm),p2=qry(rt->c[1],cm+1,r,cm+1,cr);
		if(p1.first<p2.first) return p1;
		else return p2;
	}
}

int n;
int a[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	rt[0]=bt(1,n);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		prv[i]=lo[a[i]];
		lo[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		node* e0=rt[i-1];
		if(prv[i]){
			e0=chg(e0,prv[i],0x3fff3fff,1,n,0);
		}
		rt[i]=chg(e0,i,prv[i],1,n,i);
	}
	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		pair<int,int> ml=qry(rt[r],l,r,1,n);
		if(ml.first>=l){
			cout<<0<<'\n';
		}else cout<<a[ml.second]<<'\n';
	}
	return 0; 
}