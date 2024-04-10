#include<cstdio>
#define L long long
L Get(L x,L y){
	return x>0?Get(x/y,y)+x%y+1:0;
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		L n,k;
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",Get(n,k)-1);
	} 
	return 0;
}