#include <bits/stdc++.h>
using namespace std;
const int B=20;
int n,q,rt=1,cnt=1;
int t0[15000000],t1[15000000],sz[15000000],s[2][15000000],lz[15000000];
void pushup(int id,int d){
	sz[id]=sz[s[0][id]]+sz[s[1][id]];
	t0[id]=t0[s[0][id]]|t0[s[1][id]];
	t1[id]=t1[s[0][id]]|t1[s[1][id]];
	if(s[0][id])t0[id]|=(1<<d);
	if(s[1][id])t1[id]|=(1<<d);
}
void tag(int id,int x,int d){
	if(!id||d==-1)return;
	if(x&(1<<d))swap(s[0][id],s[1][id]);
	int tmp=(t0[id]^t1[id])&x;
	t0[id]^=tmp,t1[id]^=tmp;
	lz[id]^=x;
}
void pushdown(int id,int d){
	if(lz[id]){
		tag(s[0][id],lz[id],d-1);
		tag(s[1][id],lz[id],d-1);
		lz[id]=0;
	}
}
void ins(int id,int x,int d){
	if(d==-1){
		sz[id]=1;
		return;
	}
	if((1<<d)&x){
		if(!s[1][id])s[1][id]=++cnt;
		ins(s[1][id],x,d-1);
	}else{
		if(!s[0][id])s[0][id]=++cnt;
		ins(s[0][id],x,d-1);
	}
	pushup(id,d);
}
void split(int id,int d,int p,int &x,int &y){
	if(id==0){
		x=y=0;
		return;
	}
	if(d==-1){
		x=id,y=0;
		return;
	}
	pushdown(id,d);
	if(p&(1<<d)){
		x=id,y=++cnt;
		split(s[1][x],d-1,p,s[1][x],s[1][y]);
	}else{
		x=++cnt,y=id;
		split(s[0][y],d-1,p,s[0][x],s[0][y]);
	}
	pushup(x,d),pushup(y,d);
}
int merge(int id1,int id2,int d){
	if(!id1||!id2)return id1|id2;
	if(d==-1)return id1;
	pushdown(id1,d),pushdown(id2,d);
	s[0][id1]=merge(s[0][id1],s[0][id2],d-1);
	s[1][id1]=merge(s[1][id1],s[1][id2],d-1);
	pushup(id1,d); 
	return id1;
}
void AND(int id,int p,int d){
	if(!id||(!((1<<p)&t1[id])))return;
	if(!((1<<p)&t0[id])){
		tag(id,1<<p,d);
		return;
	}
	pushdown(id,d);
	if(d==p){
		s[0][id]=merge(s[0][id],s[1][id],d-1);
		s[1][id]=0;
		pushup(id,d);
		return;
	}
	AND(s[0][id],p,d-1);
	AND(s[1][id],p,d-1);
	pushup(id,d);
}
void OR(int id,int p,int d){
	if(!id||(!((1<<p)&t0[id])))return;
	if(!((1<<p)&t1[id])){
		tag(id,1<<p,d);
		return;
	}
	pushdown(id,d);
	if(d==p){
		s[1][id]=merge(s[0][id],s[1][id],d-1);
		s[0][id]=0;
		pushup(id,d);
		return;
	}
	OR(s[0][id],p,d-1);
	OR(s[1][id],p,d-1);
	pushup(id,d);
}
int main(){
	scanf("%d%d",&n,&q);
	while(n--){
		int x;scanf("%d",&x);
		ins(1,x,B-1);
	}
	while(q--){
		int t,l,r,x,lr=0,rr=0;
		scanf("%d%d%d",&t,&l,&r);
		if(l>0)split(rt,B-1,l-1,lr,rt);
		split(rt,B-1,r,rt,rr);
		if(t==1){
			scanf("%d",&x);
			for(int i=0;i<B;i++)if(!(x&(1<<i)))AND(rt,i,B-1);
		}
		if(t==2){
			scanf("%d",&x);
			for(int i=0;i<B;i++)if(x&(1<<i))OR(rt,i,B-1);
		}
		if(t==3){
			scanf("%d",&x);
			tag(rt,x,B-1);
		}
		if(t==4)printf("%d\n",sz[rt]);
		rt=merge(merge(lr,rt,B-1),rr,B-1);
	}
}