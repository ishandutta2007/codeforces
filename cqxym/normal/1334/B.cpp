#include<stdio.h>
#include<algorithm>
#define R register int
int a[100000];
inline void Solve(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	std::sort(a,a+n);
	int l=0,r=n,mid,ans;
	long long sum;
	while(l<=r){
		sum=0;
		mid=l+r>>1;
		for(R i=mid;i!=n;i++){
			sum+=a[i];
		}
		if(sum>=(long long)x*(n-mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",n-ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}