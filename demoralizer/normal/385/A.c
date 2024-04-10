#include <stdio.h>
#include <string.h>
int main(){
	int n,c,d,f,s,t,a=1;
	scanf("%d %d\n%d %d",&n,&c,&f,&s);
	d=f-s;
	for(int i=2;i<n;i++){
		scanf("%d",&t);
		if(s-t>d){d=s-t;a=i;}
		f=s;s=t;
	}
	printf("%d",(d-c>0)?(d-c):0);
}