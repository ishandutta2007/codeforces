#include <stdio.h>
#include <string.h>
int main(){
	int n,z=0,h=0,o=0,t=0,b=0,k,q;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0)z=1;
		else if(k==100)h=1;
		else if(k/10==0)o=k;
		else if(k%10==0)t=k;
		else b=k;
	}
	q=4-(z==0)-(h==0)-(o==0)-(t==0)+(b&&o==0&&t==0);
	printf("%d\n",q);
	if(z)printf("0 ");
	if(h)printf("100 ");
	if(o)printf("%d ",o);
	if(t)printf("%d",t);
if(b&&o==0&&t==0)printf("%d",b);
}