#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
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
ll b[N],s[N];
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(i=n-1;i>0;i--){
		b[i]=a[i+1]-a[i];
	}
	sort(b+1,b+n);
	for(i=1;i<=n;i++) s[i]=s[i-1]+b[i];
	#ifdef TIME
		clock_t ST=clock();
	#endif
	read(m);
	while(m--){
		ll x,y;
		read(x,y);
		ll len=y-x+1;
		int it=upper_bound(b+1,b+n,len)-b;
		cout<<s[it-1]+len+len*(n-it)<<" ";
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}