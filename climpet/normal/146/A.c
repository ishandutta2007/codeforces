#include <stdio.h>
int main(void){
	int n,c,a=0,b=0,i;
	scanf("%d ",&n);
	for(i=0;i<n;i++){
		c=getchar()-'0';
		if(c!=4&&c!=7){
			puts("NO");
			return 0;
		}
		b+=c;
		if(i+i<n)a+=c;
	}
	puts(a+a-b?"NO":"YES");
	return 0;
}