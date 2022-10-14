#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long 
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
int cnt[1000003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),p=read(),k=read();
		for(int i=0; i<=n; i++) cnt[i]=0;
		scanf("%s",s+1);
		int y=read(),x=read();
		long long ans=1000000000000000000ll,now=1ll*(n-p)*x;
		for(int i=n; i>=p; i--,now-=x)
		{
			cnt[i%k]+=(s[i]=='0');
			ans=min(ans,now+1ll*y*cnt[i%k]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}