#include <stdio.h>
#include <string.h>
int main(){
	int n,t,s=0,z=0,c=0;
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<100;i++)
	a[i]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[t-1]++;
		s+=t;
	}
	for(int i=99;i>=0;i--){
		if(2*(z+(i+1)*a[i])<=s){
			z+=(i+1)*a[i];
			c+=a[i];
			continue;
		}
		for(int j=1;j<=a[i];j++){
			if(2*z>s){z=-1;break;}
			z+=i+1;
			c++;
		}
		if(z==-1)break;
	}
	printf("%d",c);
}