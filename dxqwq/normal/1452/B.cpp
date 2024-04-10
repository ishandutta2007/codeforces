#include<bits/stdc++.h>
#define mp make_pair
#define int long long
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
int a[100003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),sum=0,mx=0;
		for(int i=1; i<=n; i++) a[i]=read(),sum+=a[i],mx=max(mx,a[i]);
		int ans=max(mx,(long long)ceil(1.0*sum/(n-1)))*(n-1)-sum;
		printf("%lld\n",ans);
	}
	return 0;
}