#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,p,q,fz[200],fm[200];
unsigned int mem[200];
int main()
{
	n=read(),p=read(),q=read();
	for(int i=0;i<=min(n-1,p);++i)
	{
		for(int j=1;j<=i;++j) fz[j]=n-j+1,fm[j]=j;
		for(int j=1;j<=i;++j)
			for(int k=1;k<=i;++k)
			{
				int d=__gcd(fz[j],fm[k]);
				fz[j]/=d;
				fm[k]/=d;
			}
		mem[i]=1;
		for(int j=1;j<=i;++j) mem[i]*=fz[j];
	}
	unsigned int ANS=0;
	for(int t=1;t<=q;++t)
	{
		unsigned int ans=0,cur=1;
		for(int i=0;i<=min(n-1,p);++i,cur*=t) ans+=mem[i]*cur;
		ANS^=(ans*t);
	}
	printf("%u\n",ANS);
	return 0;
}
//tetu no isi to hagane no tuyosa