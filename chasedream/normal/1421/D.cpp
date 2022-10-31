#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define pii pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define pb push_back
#define int long long
#define N 500010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,c[7],v[7]; 
inline void Solve()
{
	for(int i=1;i<=6;i++)
	{
		int j=i-1;
		int k=i+1;
		if(j==0)j=6;
		if(k==7)k=1;
		if(c[i]>c[j]+c[k])c[i]=c[j]+c[k];
	}
}
signed main()
{
	int T=read();
	while(T--)
	{
		int x=read(),y=read();
		for(int i=1;i<=6;i++)c[i]=read(),v[i]=c[i];
		int ans=0;
		for(int i=1;i<=10;i++)Solve();
		if(x>=0 && y>=0)	
		{
			ans=c[1]*min(x,y);
			if(x>y)ans+=c[6]*llabs(x-y);
			else ans+=c[2]*llabs(x-y);
		}
		else if(x<=0 && y<=0)
		{
		  if(x<y)ans=-y*c[4]-(x-y)*c[3];
		  else ans=-x*c[4]-(y-x)*c[5];
		}
		else if(x<=0 && y>=0)
		{
			x=-x;
			ans=c[3]*x+c[2]*y;
		}
		else if(x>=0 && y<=0)
		{
			y=-y;
			ans=c[6]*x+c[5]*y;
		}
		cout<<ans<<endl;
	}
	return 0;
}