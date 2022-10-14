#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long ans[33];
 
signed main()
{
	for(int i=1; i<=32; i++) ans[i]=(1ll<<i)-1,ans[i]=1ll*(ans[i]+1)/2*ans[i];
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1; i<=32; i++) if(n<ans[i]) 
		{
			printf("%d\n",i-1);
			break;
		} else n-=ans[i];
	}
	return 0;
}