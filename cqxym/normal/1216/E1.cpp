#include<stdio.h>
#include<algorithm>
#define R register int
#define ll long long
#define k 1000000
ll a[k],b[k];
int Dig(int x){
	return x<10?1:Dig(x/10)+1;
}
int GetAns(ll x){
	int u=std::lower_bound(a+1,a+k,x)-a-1,v;
	if(a[u]==x){
		u--;
	}
	x-=a[u];
	v=std::lower_bound(b+1,b+k,x)-b-1;
	if(b[v]<x){
		x-=b[v];
		v++;
	}else{
		x-=b[v-1];
	}
	int t=Dig(v);
	for(R i=t-x;i>0;i--){
		v/=10;
	}
	return v%10;
}
int main(){
	int q;
	ll p;
	scanf("%d",&q);
	for(R i=1;i<k;i++){
		b[i]=b[i-1]+Dig(i);
		a[i]=a[i-1]+b[i];
	}
	for(R i=0;i<q;i++){
		scanf("%lld",&p);
		printf("%d\n",GetAns(p));
	}
	return 0;
}