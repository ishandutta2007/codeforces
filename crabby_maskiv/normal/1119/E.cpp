#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
int n,m;
ll a[N];
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++) read(a[i]);
	ll less=0;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ll ans=0;
	for(i=1;i<=n;i++){
		ll sum=min(less,a[i]/2);
		ans+=sum;
		a[i]-=sum*2;
		less-=sum;
		ans+=a[i]/3;
		a[i]-=(a[i]/3)*3;
		less+=a[i];
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}