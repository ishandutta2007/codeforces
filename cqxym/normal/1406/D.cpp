#include<stdio.h>
#define R register int
#define L long long
#define N 100001
L t[N];
inline void Print(L x,L y){
	L tem=y-x;
	if((tem&1)==1){
		tem++;
	}
	tem>>=1;
	printf("%lld\n",x+tem);
}
int main(){
	int n,q;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%lld",t+i);
	}
	for(R i=n;i!=1;i--){
		t[i]-=t[i-1];
	}
	L sum=0;
	for(R i=2;i<=n;i++){
		if(t[i]>0){
			sum+=t[i];
		}
	}
	Print(sum,t[1]);
	scanf("%d",&q);
	for(R i=0;i!=q;i++){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if(l!=1&&t[l]>0){
			sum-=t[l];
		}
		t[l]+=x;
		if(l!=1&&t[l]>0){
			sum+=t[l];
		}
		if(r<n){
			r++;
			if(t[r]>0){
				sum-=t[r];
			}
			t[r]-=x;
			if(t[r]>0){
				sum+=t[r];
			}
		}
		Print(sum,t[1]);
	}
	return 0;
}