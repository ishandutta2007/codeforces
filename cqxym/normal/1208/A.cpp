#include<cstdio>
void Solve(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	if(n%3==0){
		printf("%d\n",a);
	}else if(n%3==1){
		printf("%d\n",b);
	}else{
		printf("%d\n",a^b);
	}
}
int main(){
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Solve();
	}
	return 0;
}