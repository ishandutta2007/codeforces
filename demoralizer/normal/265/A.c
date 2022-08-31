#include <stdio.h>
#include <string.h>
int main(){
	char a[50],b[50];
	scanf("%s\n%s",a,b);
	int n=0,t=strlen(b);
	for(int i=0;i<t;i++){
		if(a[n]==b[i]){n++;}
	}
	printf("%d",n+1);
}