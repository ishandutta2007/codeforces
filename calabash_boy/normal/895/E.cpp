#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],m,n;
struct Seg_Tree{
	double sum[maxn*4],addlazy[maxn*4],multlazy[maxn*4];
	inline void Up(int x_){
		sum[x_] = sum[x_<<1]+sum[x_<<1|1];
	}
	inline void multDown(int x_){
		sum[x_<<1]*=multlazy[x_];
		sum[x_<<1|1]*=multlazy[x_];
		multlazy[x_<<1]*=multlazy[x_];
		multlazy[x_<<1|1]*=multlazy[x_];
		addlazy[x_<<1]*=multlazy[x_];
		addlazy[x_<<1|1]*=multlazy[x_];
		multlazy[x_] =1;
	}
	inline void addDown(int x_,int l_,int mid_,int r_){
		sum[x_<<1]+=(mid_-l_+1)*addlazy[x_];
		sum[x_<<1|1]+=(r_-mid_)*addlazy[x_];
		addlazy[x_<<1]+=addlazy[x_];
		addlazy[x_<<1|1]+=addlazy[x_];
		addlazy[x_]=0;
	}
	inline void Down(int x_,int l_,int mid_,int r_){
		if (multlazy[x_]!=1){
			multDown(x_);
		}
		if (addlazy[x_]!=0){
			addDown(x_,l_,mid_,r_);
		}
	}
	void build(int x,int l,int r){
		addlazy[x] =0;
		multlazy[x]=1;
		if (l==r){
			sum[x] = a[l];
			return ;
		}
		int mid = l+r >>1;
		build (x<<1,l,mid);
		build (x<<1|1,mid+1,r);
		Up(x);
	}
	double Query(int x,int l,int r,int L,int R){
		if (l>R||r<L)return 0;
		if (L<=l&&r<=R)return sum[x];
		int mid = l+r >>1;
		Down(x,l,mid,r);
		return Query(x<<1,l,mid,L,R)+Query(x<<1|1,mid+1,r,L,R);
	}
	void Update(int x,int l,int r,int L,int R,double multDelta,double addDelta){
		if (l>R||r<L)return;
		if (L<=l&&r<=R){
			sum[x] = sum[x]*multDelta+addDelta*(r-l+1);
			multlazy[x]*=multDelta;
			addlazy[x] = addlazy[x]*multDelta+addDelta;
			return;
		}
		int mid = l+r >>1;
		Down(x,l,mid,r);
		Update(x<<1,l,mid,L,R,multDelta,addDelta);
		Update(x<<1|1,mid+1,r,L,R,multDelta,addDelta);
		Up(x);
	}
}tree;
void input(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
}
void solve(){
	while (m--){
		int opt;
		scanf("%d",&opt);
		if (opt==1){
			int l1,l2,r1,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			double sum1 = tree.Query(1,1,n,l1,r1);
			double sum2 = tree.Query(1,1,n,l2,r2);
//			cout<<sum1<<" ; "<<sum2<<endl;
			tree.Update(1,1,n,l1,r1,1.0*(r1-l1)/(r1-l1+1),sum2/(r1-l1+1)/(r2-l2+1));
			tree.Update(1,1,n,l2,r2,1.0*(r2-l2)/(r2-l2+1),sum1/(r1-l1+1)/(r2-l2+1));
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%.7f\n",tree.Query(1,1,n,l,r));
		}
	}
}
int main(){
	input();
	tree.build(1,1,n);
	solve();
	return 0;
}