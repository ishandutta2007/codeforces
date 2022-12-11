#include<cstdio>
#include<algorithm>
#include<cctype>
#include<map>
using namespace std;
#define G getchar()
typedef long long ll;

int n;
ll a[7010]; int b[7010];
map<ll,int> mp;
int t[7010];
ll ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",a+i),mp[a[i]]++;
	for (int i=1;i<=n;i++) scanf("%d",b+i);
	for (int i=1;i<=n;i++) t[i]=mp[a[i]];
	for (int i=1;i<=n;i++)
	{
		bool flg=false;
		for (int j=1;j<=n;j++)
			if (t[j]>1&&(a[i]|a[j])==a[j])
			{
				flg=true;
				break;
			}
		if (flg) ans+=b[i];
	}
	printf("%I64d\n",ans);
	return 0;
}