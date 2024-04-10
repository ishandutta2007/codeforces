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
int a[1000003];
priority_queue<int> q;
signed main()
{
	int n=read(),k=read();
	for(int i=1; i<=k+1; i++) q.push(0);
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	long long ans=0,now;
	for(int i=n; i>=1; i--) now=q.top(),q.pop(),ans+=now,now+=a[i],q.push(now);
	printf("%lld\n",ans);
	return 0;
}