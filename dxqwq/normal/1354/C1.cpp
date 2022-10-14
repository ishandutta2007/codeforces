#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define pi acos(-1.0)
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		long double n;
		cin>>n;
		long double ans=1.0/tan(pi/(2.0*n));
		printf("%Lf\n",ans);
	}
	return 0;
}