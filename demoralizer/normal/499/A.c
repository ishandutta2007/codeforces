#include <stdio.h>
#include <string.h>
int main(){
	int n,x,l,r,m=1,w=0;
	scanf("%d %d",&n,&x);
	for(int i=0;i<n;i++){
		scanf("%d %d",&l,&r);
		w+=(l-m)%x+r+1-l;
		m=r+1;
	}
	printf("%d",w);
}