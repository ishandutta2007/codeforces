#include<cstdio>
int a[1000],m,n,b,t,s;
int main(){
	scanf("%d%d%d",&n,&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	scanf("%d",&b);
	for(int i=0;i<n;i++){
	  a[i]^=b;
	  for(t=0;a[i];a[i]-=a[i]&-a[i])t++;
	  if(t<=m)s++;
	}printf("%d",s);
	return 0;
}