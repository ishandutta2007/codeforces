#include<stdio.h>
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	if(s+1<=n<<1){
		printf("NO");
	}else{
		puts("YES");
		for(register int i=1;i!=n;i++){
			printf("1 ");
		}
		printf("%d\n%d",s-n+1,n); 
	}
	return 0;
}