#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=200005;
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
int n,m,k;
ll a[maxn];
pair<ll,int> b[maxn];
ll ans;
int t[maxn];
int main()
{
	int i,j;
	read(n,m,k);
	for(i=1;i<=n;i++){
		read(a[i]);
		b[i].first=a[i];b[i].second=i;
	}
	sort(b+1,b+n+1);
	for(i=n;i>n-m*k;i--){
		ans+=b[i].first;
		t[b[i].second]=1;
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	cout<<ans<<endl;
	int cnt=0,cntans=0;
	for(i=1;i<=n;i++){
		if(t[i]) cnt++;
		if(cnt>=m&&cntans<k-1){
			printf("%d ",i);
			cnt=0;cntans++;
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}