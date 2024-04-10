#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const ll mod=1000000007;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
int n,m;
ll ans[1000005];
ll a[maxn];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ans[1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				ans[a[i]/j]+=ans[a[i]/j-1];
				ans[a[i]/j]%=mod;
			}
		}
		j=int(sqrt(a[i]));if(j*j==a[i]) j--;
		for(;j>0;j--)
		{
			if(a[i]%j==0)
			{
				ans[j]+=ans[j-1];
				ans[j]%=mod;
			}
		}
		ans[1]++;
	}
	ll sum=0;
	for(i=1;i<=n;i++) sum+=ans[i];
	cout<<sum%mod;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}