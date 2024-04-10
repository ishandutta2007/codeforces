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
long long a[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=2*n; i++) a[i]=read();
	sort(a+1,a+2*n+1);
	long long ans=(a[n]-a[1])*(a[2*n]-a[n+1]);
	for(int i=1; i<=n; i++)
	ans=min(ans,(a[2*n]-a[1])*(a[n+i]-a[i+1]));
	printf("%lld\n",ans);
	return 0;
}