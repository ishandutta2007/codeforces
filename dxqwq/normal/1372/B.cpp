#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=1;
		for(int i=2; i*i<=n; i++) if(!(n%i)) 
		{
			ans=n/i;
			break;
		}
		printf("%d %d\n",ans,n-ans);
	 } 
	return 0;
}