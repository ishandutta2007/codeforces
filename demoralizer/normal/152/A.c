#include <stdio.h>
#include <string.h>
int x(int a,int b){
	return a>b?a:b;
}
int in(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,m,z=0;
	scanf("%d %d",&n,&m);
	int b[n];char a[n][m];
	for(int i=0;i<n;i++){
		scanf("%s",&a[i]);b[i]=0;}
for(int p=0;p<m;p++){
	for(int i=9;i>0;i--){
		int c=0;
		for(int j=0;j<n;j++){
		if((a[j][p]-'0')==i){c++;b[j]=1;}
		}
		if(c>0)break;
	}
}
	for(int j=0;j<n;j++)
	if(b[j])z++;
	printf("%d",z);
}