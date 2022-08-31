#include <stdio.h>
#include <string.h>
int lucky(int n){
	while(n!=0){
		if((n%10!=7)&&(n%10!=4))
		return 0;
		n/=10;
	}
	return 1;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if((n%i==0)&&lucky(i)){
		printf("YES");return 0;}
	}
	printf("NO");
}