#include <stdio.h>
#include <string.h>
int main(){
	int k,t;
	scanf("%d",&k);
	scanf("%d",&t);
	int x=t,n=t,xi=0,ni=0;
	for(int i=1;i<k;i++){
		scanf("%d",&t);
		if(t>x){x=t;xi=i;}
		if(t<=n){n=t;ni=i;}
	}
	printf("%d",xi+k-1-ni-(xi>ni));
}