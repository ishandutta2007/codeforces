#include <stdio.h>
#include <string.h>
int main(){
	int n,t,a[3]={0,0,0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[i%3]+=t;
	}
	if(a[0]>a[1]){
		if(a[0]>a[2])printf("chest");
		else printf("back");
	}
	else if(a[1]>a[2])printf("biceps");
	else printf("back");
}