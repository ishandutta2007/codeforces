#include<cstdio>
#include<algorithm>
#include<climits>
#include<iostream>
#include<cstring> 
#include<cstdlib>
#include<ctime>
#include<cctype>
//#define N 
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
long long a,b;
int ii,c;
int main()
{
	scanf("%lld%lld",&a,&b);//a0 b0 //no y0 y1
//	a=read(); b=read();
	if(b>a+10) //  //998244353
	{
		printf("%d\n",0);
		return 0; 
	} 
	c=1;
	for(long long  i=a+1; i<=b; ++i)
	{
		ii=i%10; //i= ll %10 //?
		c=c*ii%10; 
	}
	printf("%d\n",c);
}