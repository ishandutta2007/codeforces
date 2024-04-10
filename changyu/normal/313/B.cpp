#include<cstdio>
int b[100001],m,l,r;char s[100001];
int main(){
	scanf("%s",s);
	for(int i=1;s[i];i++)b[i]=b[i-1]+(s[i-1]==s[i]);
	scanf("%d",&m);
	for(;m--;)scanf("%d%d",&l,&r),printf("%d\n",b[r-1]-b[l-1]);
	return 0;
}