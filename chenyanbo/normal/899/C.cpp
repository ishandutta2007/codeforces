#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
//ll   //int   l   //uoj //_ //\n ///
int t,to1,to2,n,s1,s2,st1[69000],st2[69009];

int main()
{
	n=read();
	
	if(n%2==0)
	{
		if(n%4==0)
		{
			puts("0");
			printf("%d ",n/2);
			for(int i=1; i<=n/4; ++i)  
			printf("%d %d ",i,n-i+1);
			return 0;
		}
		puts("1");
		printf("%d ",n/2);
		for(int i=1; i<=n/4; ++i)printf("%d %d ",i,n-i+1);
		printf("%d\n",n/2);
		exit (0); 
	}
	for(int i=0; i<=n; i+=2)
	{
		st1[++to1]=i;
		st2[++to2]=i+1;
		s1+=i;
		s2+=i+1;
	}
	for(int i=to1; i; --i)
	{
		if(s1<s2)
		{
			s1+=2;
			t=st1[i];
			st1[i]=st2[i];
			st2[i]=t;
		}
		else break;
	}

	printf("%d\n",s1-s2);
	printf("%d ",n/2);
	for(int i=1; i<=to1; ++i)if(st1[i])printf("%d ",st1[i]);
}