#include<cstdio>
#define ll unsigned long long
struct Tree{
	ll L,R,Sum;
}T[800000];
ll a[200001],s[200001];
void BuildTree(ll p,ll l,ll r){
	T[p].L=l;
	T[p].R=r;
	if(l==r){
		T[p].Sum=r;
	}else{
		int mid=l+r>>1;
		BuildTree(p<<1,l,mid);
		BuildTree(p<<1|1,mid+1,r);
		T[p].Sum=T[p<<1].Sum+T[p<<1|1].Sum;
	}
}
ll Find(ll p,ll x){
	ll l=T[p].L,r=T[p].R,q;
	if(l==r){
		T[p].Sum=0;
		return r;
	}
	if(T[p<<1].Sum>x){
		q=Find(p<<1,x);
		T[p].Sum-=q;
	}else{
		q=Find(p<<1|1,x-T[p<<1].Sum);
		T[p].Sum-=q;
	}
	return q;
}
int main(){
	ll n,i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	BuildTree(1,1,n);
	for(i=n;i>0;i--){
		a[i]=Find(1,s[i]);
	}
	for(i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	return 0;
}