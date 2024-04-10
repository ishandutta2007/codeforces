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
		long long x=read(),y=read(),z=read(),p=z/x*x+y;
		if(p>z) p-=x;
		if(p+x<=z) p+=x;
		printf("%lld\n",p);
	}
	return 0;
}