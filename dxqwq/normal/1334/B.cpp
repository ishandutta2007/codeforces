#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[1919810];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; i++) a[i]=read();
		sort(a+1,a+n+1,cmp);
		int now=0;
		bool f=1;
		for(int i=1; i<=n; i++) 
		{
			now+=a[i];
			if(now/i<k) 
			{
				printf("%d\n",i-1);
				f=0;
				break;
			}
		}
		if(f) printf("%d\n",n);
	}
	return 0;
}