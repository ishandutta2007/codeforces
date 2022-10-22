#include<cstdio>
int n,a[15],s;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int I=0;I<(1<<n);I++){
	  s=0;
	  for(int i=0;i<n;i++)I&1<<i?s+=a[i]:s-=a[i];
	  if(s%360==0)return 0*puts("YES");
	}puts("NO");
	return 0; 
}