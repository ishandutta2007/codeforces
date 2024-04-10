#include <stdio.h>
#include <string.h>
int main(){
	char a[100002],b[100002],p,q;
	scanf("%s\n%s",a,b);
	int k=strlen(a),x=0;
	if(k!=strlen(b)){
		printf("NO");return 0;
	}
	for(int i=0;i<k;i++){
		if(a[i]!=b[i]){
			if(x==0){
				p=a[i];q=b[i];x=1;
			}
else if((x==1)&&(p==b[i])&&(q==a[i])){
				x=2;
			}
			else{
				printf("NO");
				return 0;
			}
		}
	}
	printf((x==2)?"YES":"NO");
}