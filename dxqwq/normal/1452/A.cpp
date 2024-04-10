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

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		int ans=0,x=min(n,m);
		ans=x*2,n-=x,m-=x;
		if(n!=m) ans+=max(n,m)*2-1;
		printf("%d\n",ans);
	}
	return 0;
}