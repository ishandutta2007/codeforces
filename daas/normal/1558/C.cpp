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
int T,n,a[2022],pos[2022],ans[20022];
void rev(int x)
{
	ans[++ans[0]]=x;
	for(int i=1;i<=x-i+1;++i)
	{
		swap(a[i],a[x-i+1]);
		pos[a[i]]=i;
		pos[a[x-i+1]]=x-i+1;
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int flag=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			pos[a[i]]=i;
			if(a[i]%2!=i%2) flag=1;
		}
		if(flag) {puts("-1");continue;}
		ans[0]=0;
		for(int i=n;i>1;i-=2)
		{
			rev(pos[i]);
			rev(pos[i-1]-1);
			rev(pos[i-1]+1);
			rev(pos[i]);
			rev(i);
		}
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!