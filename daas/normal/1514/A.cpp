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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') x=-1,c=getchar();
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int flag=0;
		for(int i=1;i<=n;++i)
		{
			int v=read(),F=0;
			for(int j=1;j*j<=v;++j)
				if(j*j==v) F=1;
			if(!F) flag=1;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}