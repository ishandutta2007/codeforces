#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),x=read();
		long long sum=0;
		int f=1,t=0;
		for(int i=1; i<=n; i++)
		{
			a[i]=read();
			if(a[i]!=x) f=0; else ++t;
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		if(f) puts("0"); else
		if(sum==1ll*x*n) puts("1");
		else if(t) puts("1");
		else puts("2");
	}
	return 0;
}