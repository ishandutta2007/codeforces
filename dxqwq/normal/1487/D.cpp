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

signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		printf("%lld\n",((int)sqrt(2*n-1)-1)>>1);
		//2n-1=a^2
	}
	return 0;
}
//a*a=b+c
//a*a=c*c-b*b
//b(b+1)=(c-1)c
//3,4,5
//5,12,13