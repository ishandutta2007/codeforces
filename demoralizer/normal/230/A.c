#include <stdio.h>
#include <string.h>
int dist(int x1,int x2,int y1,int y2){
return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main(){
	int s,n,f=0;
	scanf("%d %d",&s,&n);
	int a[n],b[n];
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				int t=b[j+1];
				b[j+1]=b[j];
				b[j]=t;
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(s>a[i]) s+=b[i];
		else{
		printf("NO");return 0;}
	}
	printf("YES");
}