#include<cstdio>
int l;char c[101],t[101];
int reverse(int d){
	for(int i=0;i<d;i++)t[i]=c[d-i-1];
	for(int i=0;i<d;i++)c[i]=t[i];
}
int main(){
	scanf("%d%s",&l,c);
	for(int i=1;i<=l;i++)if(l%i==0)reverse(i);
	printf("%s",c);
	return 0;
}