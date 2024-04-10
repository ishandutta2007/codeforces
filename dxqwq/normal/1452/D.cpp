#include<bits/stdc++.h>
#define int long long
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
const int p=998244353;
long long qp(int x,int y)
{
	int ans=1;
	for(int now=x; y; now=now*now%p,y>>=1) if(y&1) ans=ans*now%p;
	return ans;
}
int ans[200003];
signed main()
{
	int n=read();
	ans[0]=1;
	int prea=1,preb=0;
	for(int i=1; i<=n; i++) if(i&1) ans[i]=prea,preb+=ans[i],preb%=p;
	else  ans[i]=preb,prea+=ans[i],prea%=p;
	printf("%lld\n",ans[n]*qp(qp(2,n),998244351)%p);
	return 0;
}