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
int a[1000003];
bool f[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) f[read()]=1;
	n=0;
	for(int i=1; i<=1000000; ++i) if(f[i]) a[++n]=i; a[++n]=998244353;
	--n;
	int ans=0;
	for(int i=1; i<=n; i++) for(int j=a[i]*2; j-a[i]<=a[n]; j+=a[i])
	{
		int k=lower_bound(a+1,a+n+2,j)-a-1;
		ans=max(ans,a[k]%a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}