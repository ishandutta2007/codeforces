#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
inline void print(int x,char ch) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10,'\0');putchar(x%10+'0');
	if(ch!='\0') putchar(ch);return;
}
ll n,m;
int main()
{
	ll i,j;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	cin>>n>>m;
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i>=m) continue;
			ans=min(ans,i*m+n/i);
		}
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}