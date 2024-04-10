#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	int t=read();
	while(t--)
	{
		long long x=read();
		int qwq=0,awa=0;
		while(!(x%3)) x/=3,++qwq;
		while(!(x&1)) x>>=1,++awa;
		if(qwq<awa || x!=1) puts("-1"); else printf("%d\n",qwq+qwq-awa);
	}
	return 0;
}