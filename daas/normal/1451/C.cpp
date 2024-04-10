#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,K,A[30],B[30],flag;
char a[1000001],b[1000001];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		scanf("%s%s",a+1,b+1);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for(int i=1;i<=n;++i)
			A[a[i]-'a']++;
		for(int i=1;i<=n;++i)
			B[b[i]-'a']++;
		flag=0;
		for(int i=0;i<25;++i)
		{
			if(A[i]<B[i])
			{
				flag=1;
				break;
			}
			int C=A[i]-B[i];
			if(C%K)
			{
				flag=1;
				break;
			}
			A[i+1]+=C;
		}
		puts(flag?"No":"Yes");
	}
	return 0;
}