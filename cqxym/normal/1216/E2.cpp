#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll Get1(ll x){
	ll ans=0,j=1;
	for(ll i=1;i<=x;i*=10){
		if(i*10<=x){
			ans+=j*i*9;
		}else{
			ans+=(x-i+1)*j;
		}
		if(ans>1e18){
			return 1e18;
		}
		j++;
	}
	return ans;
}
ll Get2(ll x){
	ll ans=0,j=1;
	for(ll i=1;i<=x;i*=10){
		if(i*10<=x){
			ans+=j*i*9*(x-i*10+1)+j*(9*i*(9*i+1)/2);
		}else{
			ans+=j*(x-i+1)*(x-i+2)/2;
		}
		if(ans>1e18){
			return 1e18;
		}
		j++;
	}
	return ans;
}
int main(){
	int q,i,j;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		ll n,l=1,r=1e9,mid,v,x=0;
		scanf("%lld",&n);
		while(l<=r){
			mid=l+r>>1;
			if(Get2(mid)<n){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		n-=Get2(r);
		r=l;
		l=1;
		while(l<=r){
			mid=l+r>>1;
			if(Get1(mid)<n){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		n-=Get1(r);
		v=l;
		while(v>0){
			x++;
			v/=10;
		}
		n=x-n;
		for(j=1;j<=n;j++){
			l/=10;
		}
		printf("%lld\n",l%10);
	}
	return 0;
}