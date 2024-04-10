#include<cstdio>
int l,m;char a[50];
int main(){
	scanf("%d%d%s",&l,&m,a);
	while(m--)
	  for(int i=1;i<l;i++)if(a[i]==71&&a[i-1]==66)a[i]=66,a[i-1]=71,i++;
	puts(a);
	return 0;
}