#include <stdio.h>
bool have[300005];
int main(){
	int n,x,lp;
	scanf("%d",&n);
	lp=n;
	printf("1 ");
	for(int k=1;k<=n;k++){
		scanf("%d",&x);
		have[x]=true;
		while(have[lp])lp--;
		printf("%d ",k+lp-n+1);
	}
	return 0;
}