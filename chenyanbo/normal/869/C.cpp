#include<cstdio>
#include<algorithm>
#include<climits>
#include<iostream>
#include<cstring> 
#include<cstdlib>
#include<ctime>
#include<cctype>
//#define N  //
#define MO  998244353
#define kcz std // //_
using namespace kcz;  //kcz  std
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int w,ans,a,b,c_,c[5100][5100],ji[5100]; //0 1 2 3
int main()
{
	a=read(); b=read(); c_=read();
	
	ji[0]=1;
	for(int i=1; i<=5000; ++i)ji[i]=(long long )ji[i-1]*i%MO;
	c[0][0]=1;
	for(int i=1; i<=5000; ++i)
	{
		c[i][0]=1;
		for(int j=1; j<=i; ++j)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%MO;  //
	}
	w=1;
	ans=0;
	for(int i=0; i<=min(a,b); ++i)
	{// //_
		ans=((long long)ans+(long long)c[a][i]*c[b][i]%MO*ji[i]%MO)%MO;
	}
	w=(long long )w*ans%MO;
	ans=0;
	for(int i=0; i<=min(a,c_); ++i)
	{// //_
		ans=((long long)ans+(long long)c[a][i]*c[c_][i]%MO*ji[i]%MO)%MO;
	}//;
	w=(long long )w*ans%MO;
	
	ans=0; //; 
	for(int i=0; i<=min(c_,b); ++i)
	{// //_
		ans=((long long)ans+(long long)c[c_][i]*c[b][i]%MO*ji[i]%MO)%MO;
	}w=(long long )w*ans%MO; //;
	printf("%d\n",w);// %d\n
}//zkw xianduanshu