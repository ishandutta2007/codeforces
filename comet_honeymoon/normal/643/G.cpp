#include<bits/stdc++.h>
#pragma optimize("O3")
using namespace std;

const int maxN=150005;

int N,M,P,K;
int A[maxN];
struct vi{
	int a[6],len;
	void push_back(int x){a[len++]=x;}
	void clear(){len=0;}
	int size()const{return len;}
};
struct node{
	int l,r;
	int lzy;
	vi val,cnt;
	node(){val.clear();cnt.clear();lzy=-1;}
	node operator +(const node b)const{
		node c,d;c.l=l;c.r=b.r;d.l=l;d.r=b.r;
		c.val=val;c.cnt=cnt;
		for(int i=0;i<b.val.size();i++){
			int tval=b.val.a[i],tcnt=b.cnt.a[i];
			bool flg=0;
			for(int j=0;j<c.val.size();j++) if(c.val.a[j]==tval) c.cnt.a[j]+=tcnt,flg=1;
			if(flg) continue;
			c.val.push_back(tval);c.cnt.push_back(tcnt);
			if(c.val.size()<=K) continue;
			int minpos=0;
			for(int j=1;j<c.val.size();j++) if(c.cnt.a[j]<c.cnt.a[minpos]) minpos=j;
			d.val.clear();d.cnt.clear();
			for(int j=0;j<c.val.size();j++)if(j!=minpos)
				d.val.push_back(c.val.a[j]),d.cnt.push_back(c.cnt.a[j]-c.cnt.a[minpos]);
			c=d;
		}
		return c;
	}
	void cover(int w){
		val.clear();cnt.clear();
		val.push_back(w);cnt.push_back(r-l+1);
		lzy=w; 
	}
}T[maxN<<2];
void pushdown(int x){
	if(T[x].lzy==-1) return;
	T[x<<1].cover(T[x].lzy);T[x<<1|1].cover(T[x].lzy);
	T[x].lzy=-1;
}

void Build(int x,int l,int r){
	if(l==r){T[x].l=T[x].r=l;T[x].cover(A[l]);return;}
	int mid=(l+r)>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	T[x]=T[x<<1]+T[x<<1|1];
}
void Update(int x,int l,int r,int L,int R,int w){
	if(L<=l&&r<=R){T[x].cover(w);return;}
	int mid=(l+r)>>1;pushdown(x);
	if(L<=mid) Update(x<<1,l,mid,L,R,w);
	if(R>mid) Update(x<<1|1,mid+1,r,L,R,w);
	T[x]=T[x<<1]+T[x<<1|1];
}
node Query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R) return T[x];
	int mid=(l+r)>>1;pushdown(x);
	if(L>mid) return Query(x<<1|1,mid+1,r,L,R);
	if(R<=mid) return Query(x<<1,l,mid,L,R);
	return Query(x<<1,l,mid,L,R)+Query(x<<1|1,mid+1,r,L,R);
}

int main(){
//	freopen("work.in","r",stdin);
//	freopen("work.out","w",stdout);
	scanf("%d%d%d",&N,&M,&P);K=100/P;
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	Build(1,1,N);
//	int clk=0;
	while(M--){
		int opt,l,r;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			int w;scanf("%d",&w);
			Update(1,1,N,l,r,w);
		}
		else{
			node ans=Query(1,1,N,l,r);
			printf("%d ",ans.val.size());//clk+=ans.val.size();
			for(int i=0;i<ans.val.size();i++) printf("%d ",ans.val.a[i]);
			printf("\n");
		}
//		if(M%10000==0) cerr<<clk<<endl,clk=0; 
	}
}