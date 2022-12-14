#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define ll long long
#define ak *
char qwq;
ll n,m,k,ans,cnt,a[200005],vis[200005];
pair<ll,ll>p[200005];
inline ll read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
int main()
{
	n=read();m=read();k=read();
	for(re i=1;i<=n;i++) a[i]=p[i].first=read(),p[i].second=i;
	sort(p+1,p+n+1);
	for(re i=n;i>=n-(m*k)+1;i--) ans+=p[i].first,vis[p[i].second]=1;
	cout<<ans<<endl;
	for(re i=1,now=0;i<=n;i++)
	{
		if(vis[i]) now++;
		if(now>=m) 
		{
			cnt++,now=0;
			if(cnt!=k) printf("%d ",i);
		}
	}
}