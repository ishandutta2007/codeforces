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
int T,z[20],top,n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int val=10;
		top=0;
		while(n)
		{
			z[++top]=n%10;
			n/=10;
		}
		for(int i=1;i<=top-1;++i) val=min(val,z[i]);
		if(top!=2) val=min(val,z[top]);
		printf("%d\n",val);
	}
	return 0;
}
//ore no turn,draw!