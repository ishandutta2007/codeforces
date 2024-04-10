#include<bits/stdc++.h>
using namespace std;

const int maxn=300005;
const long long mdn=1000000009;
const long long csa=276601605;//383008016;
const long long csb=691504013;
const long long csc=308495997;
const long long ksb=308495996;
const long long ksc=691504012;

struct node{
	long long sm,lt1,lt2;
	int l,r;
	node* c[2];
}; 

long long a[maxn];
long long psb[maxn],psc[maxn];
int n;

node pool[maxn*4];int ps; 

node* nwnode(int l,int r){
	node* nw=pool+ps++; 
	nw->l=l;nw->r=r;nw->sm=0;nw->lt1=0;nw->lt2=0;nw->c[0]=nw->c[1]=NULL;
	return nw; 
}

void pu(node* rt){
	if(!rt) return;
	if(rt->l==rt->r) return;
	rt->sm=(rt->c[0]->sm+rt->c[1]->sm)%mdn; 
}

void pd(node* rt){
	if(!rt) return;
	if(rt->lt1==0&&rt->lt2==0) return;
	//rt->sm=(rt->sm+((((((rt->lt1*((((1-psb[rt->r-rt->l+1]+mdn)%mdn)*ksb)%mdn)%mdn))%mdn-(rt->lt2*(((1-psc[rt->r-rt->l+1]+mdn)%mdn)*ksc)%mdn)%mdn)%mdn+mdn)%mdn)%mdn*csa)%mdn)%mdn;
	rt->sm+=(((csa*rt->lt1)%mdn)*(((1ll-psb[rt->r-rt->l+1]+mdn)%mdn*ksb)%mdn))%mdn;
	rt->sm-=(((csa*rt->lt2)%mdn)*(((1ll-psc[rt->r-rt->l+1]+mdn)%mdn*ksc)%mdn))%mdn;
	rt->sm%=mdn;
	rt->sm+=mdn;
	rt->sm%=mdn;
	if(rt->l!=rt->r){
		rt->c[0]->lt1+=rt->lt1;rt->c[0]->lt2+=rt->lt2;
		rt->c[1]->lt1+=rt->lt1*psb[(rt->l+rt->r )/2-rt->l+1];rt->c[1]->lt2+=rt->lt2*psc[(rt->l+rt->r )/2-rt->l+1]; 
		rt->c[0]->lt1%=mdn;rt->c[0]->lt2%=mdn;rt->c[1]->lt1%=mdn;rt->c[1]->lt2%=mdn;
	}
	rt->lt1=0;
	rt->lt2=0;
}

node* bt(int l,int r){
	node* nw=nwnode(l,r);
	if(l==r){
		nw->sm=a[l];
	} else{
		nw->c[0]=bt(l,(l+r)/2);
		nw->c[1]=bt((l+r)/2+1,r);
		pu(nw);
	}
	return nw;
}

void chg(node* rt,int l,int r,long long k1,long long k2){
	int cl=rt->l,cr=rt->r,cm=(cl+cr)/2;
	pd(rt);
	if(cl==l&&cr==r){
		rt->lt1+=k1;rt->lt1%=mdn; 
		rt->lt2+=k2;rt->lt2%=mdn;
		pd(rt);
		return;
	}else if(r<=cm){
		chg(rt->c[0],l,r,k1,k2);
	}else if(l>cm){
		chg(rt->c[1],l,r,k1,k2);
	}else{
		chg(rt->c[0],l,cm,k1,k2);
		chg(rt->c[1],cm+1,r,(k1*psb[cm-l+1])%mdn,(k2*psc[cm-l+1])%mdn);
	}
	pd(rt->c[0]);pd(rt->c[1]);pu(rt);
}

long long qry(node* rt,int l,int r){
	int cl=rt->l,cr=rt->r,cm=(cl+cr)/2;
	pd(rt);
	if(cl==l&&cr==r){
		return rt->sm;
	}else if(r<=cm){
		return qry(rt->c[0],l,r);
	}else if(l>cm){
		return qry(rt->c[1],l,r);
	}else{
		return (qry(rt->c[0],l,cm)+qry(rt->c[1],cm+1,r))%mdn;
	}
}

void dfs(node* rt){
	if(!rt) return;
	cout<<rt->l<<rt->r<<':'<<rt->sm<<'/'<<rt->lt1<<'/'<<rt->lt2<<endl; 
	dfs(rt->c[0]);
	dfs(rt->c[1]); 
}
int main(){
	psb[0]=1;psc[0]=1;
	for(int i=1;i<maxn;i++) psb[i]=(psb[i-1]*csb)%mdn;
	for(int i=1;i<maxn;i++) psc[i]=(psc[i-1]*csc)%mdn;/*
	node* rt=new node;rt->sm=0;rt->lt1=1;rt->lt2=1;rt->l=1;rt->r=2;
	rt->sm+=(((csa*rt->lt1)%mdn)*(((1ll-psb[rt->r-rt->l+1]+mdn)%mdn*ksb)%mdn))%mdn;
	rt->sm-=(((csa*rt->lt2)%mdn)*(((1ll-psc[rt->r-rt->l+1]+mdn)%mdn*ksc)%mdn))%mdn;
	rt->sm%=mdn;
	rt->sm+=mdn;
	rt->sm%=mdn;
	cout<<rt->sm;*/
	int q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	node* rt=bt(1,n);
	while(q--){
		long long op,l,r;
		scanf("%I64d%I64d%I64d",&op,&l,&r);
		switch(op){
			case 1:
				chg(rt,l,r,csb,csc);
				break;
			case 2:
				printf("%I64d\n",qry(rt,l,r));
				break;
		}
		//dfs(rt);
	}
	return 0;
}