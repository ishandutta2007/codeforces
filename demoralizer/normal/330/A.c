#include <stdio.h>
#include <string.h>
int main(){
	int r,c,k=0;
	scanf("%d %d",&r,&c);
	char a[r][c];
	for(int i=0;i<r;i++)
		scanf("%s",a[i]);
	for(int i=0;i<r;i++){
		int f=0;
		for(int j=0;j<c;j++)
			if(a[i][j]=='S'){f=1;break;}
		if(f) continue;
		for(int j=0;j<c;j++) a[i][j]='e';
		k+=c;
	}
	for(int i=0;i<c;i++){
		int f=0;
		for(int j=0;j<r;j++)
			if(a[j][i]=='S'){f=1;break;}
		if(f) continue;
		for(int j=0;j<r;j++)
		if(a[j][i]=='.')k++;
	}
	printf("%d",k);
}