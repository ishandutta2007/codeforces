#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
#define P 998244353
int d[200001],sum[200001];
inline int PowMod(int x,int y){
	int res=1;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int main(){
	int x,y,n,m;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		scanf("%d",d+i);
	}
	sort(d+1,d+1+n);
	for(R i=1;i<=n;i++){
		sum[i]=(sum[i-1]+d[i])%P;
	}
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		int t=lower_bound(d+1,d+1+n,y)-d-1;
		if(n-t<x){
			puts("0");
		}else{
			int s=(L)PowMod(n-t,P-2)*(n-t-x)%P*(sum[n]-sum[t]+P)%P+(L)PowMod(n-t+1,P-2)*(n-t+1-x)%P*sum[t]%P;
			printf("%d\n",s%P);
		}
	}
	return 0;
}