#include <stdio.h>
#include <string.h>
int main(){
	int n,u=0,l=0,x,y,k=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		u+=x;l+=y;
		if((x%2)^(y%2)) k=1;
	}
	if((u%2)&&(l%2)){
		if(k&&(n>1))printf("1");
		else printf("-1");
	}
	else if((u%2)^(l%2))
		printf("-1");
	else printf("0");
}