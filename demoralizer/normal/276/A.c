#include <stdio.h>
#include <string.h>
int main(){
	int n,k,f,t,j;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d %d",&f,&t);
		if(t>k)f-=(t-k);
		if(i==0||f>j)j=f;
	}
	printf("%d",j);
}