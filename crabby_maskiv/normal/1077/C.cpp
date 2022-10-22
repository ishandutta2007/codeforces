#include<bits/stdc++.h>
//#define TIME
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
ll a[maxn];
ll ans[maxn],len;
ll sum;
int vis[1000005];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		vis[a[i]]++;
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<=n;i++)
	{
		if((sum-a[i])%2) continue;
		if((sum-a[i])>2000000) continue;
		vis[a[i]]--;
		if(vis[(sum-a[i])/2]>0) ans[++len]=i;
		vis[a[i]]++;
	}
	cout<<len<<endl;
	for(i=1;i<=len;i++) cout<<ans[i]<<" ";
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}