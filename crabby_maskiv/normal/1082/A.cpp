#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const ll inf=0x3f3f3f3f3f;
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
int T;
ll n,m;
ll x,y,d;
ll fun(ll k)
{
	if(k<0) return -k;
	return k;
}
int main()
{
	int i,j;
	read(T);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	while(T--)
	{
		cin>>n>>x>>y>>d;
		ll ans=inf;
		if(fun(y-x)%d==0) ans=min(ans,fun(y-x)/d);
		if((y-1)%d==0) ans=min(ans,((x-1)+(d-1))/d+(y-1)/d);
		if((n-y)%d==0) ans=min(ans,((n-x)+(d-1))/d+(n-y)/d);
		if(ans==inf) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}