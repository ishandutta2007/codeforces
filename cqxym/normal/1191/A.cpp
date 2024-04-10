#include<cstdio>
int main(){
	int a;
	scanf("%d",&a);
	if(a%4==1){
		printf("0 A");
	}else if(a%4==2){
		printf("1 B");
	}else if(a%4==3){
		printf("2 A");
	}else{
		printf("1 A");
	}
	return 0;
}