#include <stdio.h>
int df(int a,int b){
	return a>b?(a-b):(b-a);
}
int main(){
	int n,d,x;
	scanf("%d",&n);
	int a[n+1];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	a[n]=a[0];x=0;d=df(a[0],a[1]);
	for(int i=0;i<n;i++){
		if(d>df(a[i],a[i+1])){
			d=df(a[i],a[i+1]);
			x=i;
		}
	}
	printf("%d %d",x%n+1,(x+1)%n+1);
}