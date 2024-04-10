#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
ll base;
int main(){
	int i,j;
	read(n);
	for(i=1;i<=n;i++){
		ll x,y;read(x,y);
		base+=y*(n-1);
		a[i]=x-y;
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	sort(a+1,a+n+1);
	ll ans=base;
	for(i=n;i>0;i--){
		ans+=a[i]*(n-i);
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	cout<<ans;
	return 0;
}