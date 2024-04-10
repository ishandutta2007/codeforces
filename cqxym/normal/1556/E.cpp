#include<stdio.h>
#define R register int
#define L long long
#define I inline
I L Max(const L x,const L y){
	return x>y?x:y;
}
I L Min(const L x,const L y){
	return x<y?x:y;
}
L maxS[400000],minS[400000],s[100001];
int a[100001];
I void Init(int p,int lf,int rt){
	if(lf==rt){
		maxS[p]=minS[p]=s[rt];
	}else{
		Init(p<<1,lf,lf+rt>>1);
		Init(p<<1|1,lf+rt+2>>1,rt);
		maxS[p]=Max(maxS[p<<1],maxS[p<<1|1]);
		minS[p]=Min(minS[p<<1],minS[p<<1|1]);
	}
}
I L GetMax(int p,int lf,int rt,const int l,const int r){
	if(l<=lf&&rt<=r){
		return maxS[p];
	}
	int mid=lf+rt>>1;
	L res=-999999999999999;
	if(l<=mid){
		res=GetMax(p<<1,lf,mid,l,r);
	}
	if(r>mid){
		res=Max(res,GetMax(p<<1|1,mid+1,rt,l,r));
	}
	return res;
}
I L GetMin(int p,int lf,int rt,const int l,const int r){
	if(l<=lf&&rt<=r){
		return minS[p];
	}
	int mid=lf+rt>>1;
	L res=999999999999999;
	if(l<=mid){
		res=GetMin(p<<1,lf,mid,l,r);
	}
	if(r>mid){
		res=Min(res,GetMin(p<<1|1,mid+1,rt,l,r));
	}
	return res;
}
int main(){
	int n,q,l,r;
	scanf("%d%d",&n,&q);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i<=n;i++){
		scanf("%d",&l);
		a[i]=l-a[i];
		s[i]=s[i-1]+a[i];
	}
	Init(1,1,n);
	for(R i=0;i!=q;i++){
		scanf("%d%d",&l,&r);
		L x=GetMax(1,1,n,l,r)-s[l-1],y=GetMin(1,1,n,l,r)-s[l-1];
		if(y<0||s[r]!=s[l-1]){
			puts("-1");
		}else{
			printf("%lld\n",x);
		}
	}
	return 0;
}