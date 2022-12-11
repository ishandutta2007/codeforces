#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MN=100005;
pair<int,int> p[MN];
int f[MN],ans;
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)p[i].first=read(),p[i].second=read();
	sort(p+1,p+n+1);
	for(i=1;i<=n;++i)ans=max(ans,f[i]=
		f[lower_bound(p+1,p+n+1,make_pair(p[i].first-p[i].second,0))-p-1]+1);
	printf("%d",n-ans);
}