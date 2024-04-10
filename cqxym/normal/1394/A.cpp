#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
L a[100001],b[100001];
inline void Solve(L*A,int n){
	sort(A+1,A+n+1);
	reverse(A+1,A+n+1);
	for(R i=1;i<=n;i++){
		A[i]+=A[i-1];
	}
}
inline void Max(L&x,L y){
	x=x>y?x:y;
}
int main(){
	int n,d,m,k=0,l=0,x;
	scanf("%d%d%d",&n,&d,&m);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if(x>m){
			k++;
			a[k]=x;
		}else{
			l++;
			b[l]=x;
		}
	}
	L res=0;
	if(k==0){
		for(R i=1;i<=n;i++){
			res+=b[i];
		}
		printf("%lld",res);
		return 0;
	}
	Solve(a,k);
	Solve(b,l);
	for(R i=l+1;i<=n;i++){
		b[i]=b[l];
	}
	for(R i=(k+d)/(d+1);i<=k;i++){
		if((L)(i-1)*(d+1)+1<=n){
			Max(res,a[i]+b[n-(i-1)*(d+1)-1]);
		}
	}
	printf("%lld",res);
	return 0;
}