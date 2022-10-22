#include<cstdio>
int l,t,s;char a[100002],b[100002];
int Cnt(int a,int b,int c,int d){return (a!=b)+(a!=c)+(a!=d)+(b!=c)+(b!=d)+(d!=c);}
int main()
{
	scanf("%d%s%s",&l,a+1,b+1);
	for(int i=1;i+i<=l;i++){
	  t=Cnt(a[i],b[i],a[l-i+1],b[l-i+1]);
	  if(t==3||t==5&&a[i]!=a[l-i+1])s++;
	  if(t==6||t==5&&a[i]==a[l-i+1])s+=2;
	}
	printf("%d",s+((l&1)&&a[l+1>>1]!=b[l+1>>1]));
	return 0;
}