#include<cstdio>
int main(){
	int n,i,ct1=0,ct2=0,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x%2==1){
			ct1++;
		}else{
			ct2++;
		}
	}
	if(ct1>ct2){
		printf("%d",ct2);
	}else{
		printf("%d",ct1);
	}
	return 0;
}