#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=1005;
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
ll b[N];
ll h;
int main()
{
	int i,j;
	cin>>n>>h;
	for(i=1;i<=n;i++) cin>>a[i];
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<=n;i++){
		ll t=0;
		for(j=1;j<=i;j++) b[j]=a[j];
		sort(b+1,b+i+1);
		for(j=i;j>0;){
			t+=max(b[j],b[j-1]);
			if(t>h) break;
			j-=2;
		}
		if(t>h) break;
	}
	cout<<i-1;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}