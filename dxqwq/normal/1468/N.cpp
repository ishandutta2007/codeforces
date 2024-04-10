#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

signed main()
{
	int T=read();
	while(T--)
	{
		int x=read(),y=read(),z=read();
		int a=read(),b=read(),c=read(),d=read(),e=read();
		x-=a,y-=b,z-=c;
		if(x<0||y<0||z<0) puts("No");
		else
		{
			if(max(d-x,0)+max(e-y,0)<=z) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}