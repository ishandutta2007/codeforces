#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool F[13];
bool f(int x)
{
	for(int i=2; i<=9; i++) F[i]=0;
	int y=x;
	while(y) F[y%10]=1,y/=10;
	for(int i=2; i<=9; i++) if(F[i]&&x%i) return 0;
	return 1;
}
signed main()
{
	int T=read();
	while(T--)
	{
		long long x=read();
		while(!f(x)) ++x;
		printf("%lld\n",x);
	}
	return 0;
}