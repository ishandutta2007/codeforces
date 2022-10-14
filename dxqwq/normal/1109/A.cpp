#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int x[2000003],y[2000003];
long long ans;
signed main()
{
	int n=read();
	y[0]=1;
	for(int i=1,a=0; i<=n; i++) 
	{
		a^=read();
		if(i&1)
		{
			ans+=x[a],++x[a];
		}
		else
		{
			ans+=y[a],++y[a];
		}
	}
	printf("%lld\n",ans);
	return 0;
}