#include<stdio.h>
bool b[10];
bool Check(int x){
	for(register int i=0;i<10;i++){
		b[i]=false;
	}
	while(x>0){
		if(b[x%10]==false){
			b[x%10]=true;
		}else{
			return false;
		}
		x/=10;
	}
	return true;
}
int main(){
	int l,r;
	scanf("%d%d",&l,&r);
	while(l<=r){
		if(Check(l)==true){
			printf("%d",l);
			return 0;
		}
		l++;
	}
	printf("-1");
	return 0;
}