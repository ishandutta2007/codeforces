#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
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
	int last=0,len=0;
	for(i=1;i<=n;i++) read(a[i]);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=(a[i])*(n-a[i]+1);
	for(i=1;i<n;i++)
		ans-=(min(a[i],a[i+1]))*(n-max(a[i],a[i+1])+1);
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	cout<<ans;
	return 0;
}