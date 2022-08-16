#include <stdio.h>
int main()
{
	long long int n,f,s,t,m=0,c=0;
	scanf("%I64d %I64d %I64d",&n,&f,&s);
	for(long long int i=2;i<n;i++){
		scanf("%I64d",&t);
		if(t==f+s)c++;
		else c=0;
		if(c>m)m=c;
		f=s;s=t;
	}
	printf("%I64d",(n==1)?1:(m+2));
}