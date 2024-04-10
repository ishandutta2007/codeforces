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
int x[1003],y[1003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; i++) x[i]=read(),y[i]=read();
		bool f=0;
		for(int i=1; i<=n; i++)
		{
			int mx=0;
			for(int j=1; j<=n; j++) if(i!=j) mx=max(mx,abs(x[i]-x[j])+abs(y[i]-y[j]));
			if(mx<=k)
			{
				f=1;
				break;
			}
		}
		if(f) puts("1"); else puts("-1");
	}
	return 0;
}