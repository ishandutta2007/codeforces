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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,a[3000],n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=a[i-1]^read();
		int flag=0;
		for(int i=1;i<n;++i)
		{
			int F=0,las=i+1;
			for(int j=i+1;j<=n;++j) if((a[j]^a[las-1])==a[i]) las=j+1;
			if((a[n]^a[las-1])==0 && las!=i+1) {flag=1;break;}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}