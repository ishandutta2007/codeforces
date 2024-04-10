#include<cstdio>
int n,g[10],f;char a[200001];
int main(){
	scanf("%d%s",&n,a+1);
	for(int i=1;i<=9;i++)scanf("%d",g+i);
	f=-1;
	for(int i=1;a[i];i++){
	  if(g[a[i]-48]>a[i]-48&&f<0)f=1;
	  if(g[a[i]-48]<a[i]-48&&f>0)f=0;
	  printf("%d",f>0?g[a[i]-48]:a[i]-48);
	}return 0;
}