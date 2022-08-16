#include <stdio.h>
#include <string.h>
int main(){
	int n,t,k,z=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		int c=0;
		while(t!=0){
			if((t%10)==4||(t%10)==7)
			c++;
			t/=10;
		}
		if(c<=k)z++;
	}
	printf("%d",z);
}