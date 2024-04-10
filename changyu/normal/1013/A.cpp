#include<cstdio>
int n,s,t,s1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&t),s+=t;
	for(int i=0;i<n;i++)scanf("%d",&t),s1+=t;
	return 0*puts(s1<=s?"Yes":"No");
}