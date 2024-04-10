#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
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
string s;
int main()
{
	cin>>s;
	int len=s.length(),zone=-1,F=0;
	for(register int i=0;i<len;++i)
		if(s[i]=='1')
		{
			if(zone==-1)
				zone=len-1-i;
			else
				F=1;
		}
	if(zone==-1 || zone==0)
		puts("0");
	else
		if(zone%2==0)
			printf("%d\n",zone/2+1-(F^1));
		else
			printf("%d\n",zone/2+1);
	return 0;
}