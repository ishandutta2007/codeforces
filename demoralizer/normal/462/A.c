#include <stdio.h>
#include <string.h>
int main(){
	int n,t=0;char r;
	scanf("%d",&n);
	char a[n][n];
	for(int i=0;i<n;i++)
  	for(int j=0;j<n;j++){
  		scanf("%c",&r);
  		if(r=='\n'){j--;continue;}
  		a[i][j]=r;
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){t=0;
			if(i>0&&a[i-1][j]=='o')t++;
			if(j>0&&a[i][j-1]=='o')t++;
			if(i<n-1&&a[i+1][j]=='o')t++;
			if(j<n-1&&a[i][j+1]=='o')t++;
	if(t%2){printf("NO");return 0;}
		}
	}
	printf("YES");
}