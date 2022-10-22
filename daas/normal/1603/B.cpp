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
int T,x,y;
int main()
{
	T=read();
	while(T--)
	{
		x=read(),y=read();
		if(x>y) printf("%d\n",x+y);
		else if(y%x==0) printf("%d\n",y);
		else
		{
			int t=(y/x*x+y)/2;
			printf("%d\n",t);
		}
	}
	return 0;
}
//ore no turn,draw!