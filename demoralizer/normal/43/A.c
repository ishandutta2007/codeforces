#include <stdio.h>
#include <string.h>
int eq(char a[],char b[]){
	int n=strlen(a);
	if(n!=strlen(b))return 0;
	for(int i=0;i<n;i++)
	if(a[i]!=b[i])return 0;
	return 1;
}
void sc(char a[],char b[]){
	for(int i=0;i<11;i++){
		a[i]=b[i];
	}	
}
int main(){
	int n,f1=0,f2=0;
	scanf("%d",&n);
	char a[n][11];
	for(int i=0;i<n;i++)
		scanf("%s",a[i]);
	char t1[11],t2[11];sc(t1,a[0]);
	for(int i=0;i<n;i++){
		if(eq(a[i],t1))f1++;
		else {sc(t2,a[i]);f2++;}
	}
	printf("%s",f2>f1?t2:t1);
}