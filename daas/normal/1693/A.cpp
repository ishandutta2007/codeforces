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
int T,n,a[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		ll ans=0;
		int flag=1,ed=n;
		while(!a[ed] && ed>=1) --ed;
		if(!ed) {puts("Yes");continue;}
		for(int i=1;i<=ed;++i)
		{
			int val=a[i];
			if(val>0) ans+=val;
			else
			{
				ans+=val;
				if(ans<0 || (ans==0 && i!=ed)) flag=0;
			}
		}
		puts((flag==1 && ans==0)?"Yes":"No");
	}
	return 0;
}
//tetu no isi to hagane no tuyosa