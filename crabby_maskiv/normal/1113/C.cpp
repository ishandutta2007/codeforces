#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=300005;
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
int a[maxn],sum[maxn];
map<int,int> even,odd;
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	even[0]++;
	ll ans=0;
	for(i=1;i<=n;i++){
		if(i&1){
			ans+=odd[sum[i]];
			odd[sum[i]]++;
		}
		else{
			ans+=even[sum[i]];
			even[sum[i]]++;
		}
		
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}