#include<cstdio>
#include<algorithm>
#include<cctype>
#include<map>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;

int n,w[200010];
ll dp[200010];
map<int,ll> bin;  ll ans;
int main()
{
	n=read(); for (int i=1;i<=n;i++) w[i]=read();
	for(int i=n;i;i--)
	{
		dp[i]=bin[i-w[i]]+w[i];
		bin[i-w[i]]=max(bin[i-w[i]],dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}