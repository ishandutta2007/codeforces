#include <stdio.h>
#include <string.h>
int main(){
	int n,a=0,b=0,c=0,p,q,r;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&p,&q,&r);
		a+=p;b+=q;c+=r;
	}
	if(a||b||c)printf("NO");
	else printf("YES");
}