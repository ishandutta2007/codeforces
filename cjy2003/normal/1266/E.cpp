#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,a[200020],q,cnt[200020];
map<int,int>mp[200020];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),ans+=a[i];
	scanf("%d",&q);
	int x,y,z;
	while(q--)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(mp[x][y])
		{
			int c=mp[x][y];
			--cnt[c];
			if(cnt[c]<a[c])++ans;
			mp[x].erase(y);
		}
		if(z)
		{
			mp[x][y]=z;
			++cnt[z];
			if(cnt[z]<=a[z])--ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
}