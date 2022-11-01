#include<stdio.h>
inline bool Check(int n){
	if((n&n-1)!=0){
		return false;
	}
	int res=0;
	while(n!=1){
		res^=1;
		n>>=1;
	}
	return res==1;
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	if((n&1)==1||Check(n)){
		puts("Bob");
	}else{
		puts("Alice");
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