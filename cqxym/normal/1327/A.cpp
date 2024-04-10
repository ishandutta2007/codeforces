#include<stdio.h>
inline void Solve(){
	int n,k;
	scanf("%d%d",&k,&n);
	if((long long)n*n<=k&&(k-n)%2==0){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve(); 
	}
	return 0;
}