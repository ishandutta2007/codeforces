#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
	LL n,ans=0;
	char p;
	scanf("%I64d%c",&n,&p);
	ans+=(n-1)/4*16;
	if(n%2==0)ans+=7;
	if(p=='f')ans+=1;
	if(p=='e')ans+=2;
	if(p=='d')ans+=3;
	if(p=='a')ans+=4;
	if(p=='b')ans+=5;
	if(p=='c')ans+=6;
	cout<<ans<<endl;
	return 0;
}