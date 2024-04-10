#include<cstdio>
#include<map>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
map<ll,bool> mp;
ll a[MN+5];
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)a[i]=a[i-1]+read();
	if(a[n]&1)return 0*puts("NO");
	for(i=1;i<=n;++i)
	{
		mp[a[i]-a[i-1]]=1;
		if(a[n]<2*a[i]&&mp[a[i]-a[n]/2])return 0*puts("YES");
	}
	mp.clear();
	for(i=n;i;--i)
	{
		mp[a[i]-a[i-1]]=1;
		if(a[n]>2*a[i-1]&&mp[a[n]/2-a[i-1]])return 0*puts("YES");
	}
	puts("NO");
}