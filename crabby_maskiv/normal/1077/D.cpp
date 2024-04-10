#include<bits/stdc++.h>
#define TIME
using namespace std;
typedef long long ll;
const int maxn=200005;
const int inf=0x3f3f3f3f;
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
int vis[maxn];
int a[maxn];
int ans[maxn],len;
bool check(int key)
{
	len=0;
	int cnt=0;
	for(int i=0;i<maxn;i++)
	{
		if(vis[i]>=key)
		{
			for(int j=1;j<=(vis[i])/key;j++)
			    ans[++len]=i;
		}
		cnt+=vis[i]/key;
	}
	if(cnt<m) return 0;
	return 1;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[a[i]]++;
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	int l=1,r=n;
	while(r-l>5)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(i=r;i>=l;i--)
	{
		if(check(i))
		{
			for(j=1;j<=m;j++) cout<<ans[j]<<" ";
			return 0;
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}