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
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
ll n,m;
int main()
{
	ll i,j;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	cin>>n>>m;
	ll l=1,r=m;
	while(r-l>5)
	{
		ll mid=(l+r)/2;
		ll tmp=(m+mid-1)/mid;
		if(tmp>n) l=mid;
		else r=mid;
	}
	for(i=l;i<=r;i++)
	{
		if((m+i-1)/i<=n) 
		{
			cout<<i;
			return 0;
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}