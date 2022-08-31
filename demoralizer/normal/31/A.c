#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			for(int k=0;k<n;k++){
				if(i==k||j==k) continue;
				if(a[i]==a[j]+a[k]){
					printf("%d %d %d",i+1,j+1,k+1);
					return 0;
				}
			}
		}
	}
	printf("-1");
}