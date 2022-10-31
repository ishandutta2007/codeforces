#include<stdio.h>
#define R register int
#define L long long
#define I inline
int p[200001],pos[200001],a[200001];
L sum[200001];
I L Min(L x,L y){
	return x<y?x:y;
}
struct SegmentTree{
	int l,r;
	L mn,lazy;
}T[1000000];
I void Build(int p,int l,int r){
	T[p].l=l;
	T[p].r=r;
	if(l!=r){
		Build(p<<1,l,l+r>>1);
		Build(p<<1|1,l+r+2>>1,r);
		T[p].mn=Min(T[p<<1].mn,T[p<<1|1].mn);
	}else{
		T[p].mn=sum[r];
	}
}
I void PutDown(int p){
	T[p].mn+=T[p].lazy;
	if(T[p].l!=T[p].r){
		T[p<<1].lazy+=T[p].lazy;
		T[p<<1|1].lazy+=T[p].lazy;
	}
	T[p].lazy=0;
}
I void Modify(int p,int &l,int &r,int &d){
	PutDown(p);
	if(T[p].l>=l&&T[p].r<=r){
		T[p].lazy+=d;
		return;
	}
	int mid=T[p].l+T[p].r>>1;
	if(l<=mid){
		Modify(p<<1,l,r,d);
	}
	if(r>mid){
		Modify(p<<1|1,l,r,d);
	}
	PutDown(p<<1);
	PutDown(p<<1|1);
	T[p].mn=Min(T[p<<1].mn,T[p<<1|1].mn);
}
I void Change(int l,int r,int d){
	if(l<=r){
		Modify(1,l,r,d);
	}
}
I L GetMin(){
	PutDown(1);
	return T[1].mn;
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",p+i);
		pos[p[i]]=i;
	}
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	Build(1,1,n-1);
	L ans=Min((L)a[1],(L)a[n]);
	for(R i=1;i!=n;i++){
		Change(1,pos[i]-1,a[pos[i]]);
		Change(pos[i],n-1,-a[pos[i]]);
		ans=Min(ans,GetMin());
	}
	printf("%lld",ans);
	return 0;
}