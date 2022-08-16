#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,k;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;;i++){
		k=1;
		for(int j=0;j<n;j++)
			if(a[j]==i){k=0;break;}
		if(k){printf("%d",i);return 0;}
	}
}