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
int n,m;
int a[maxn];
pair<int,int> loc[maxn];
int ab(int x){
	if(x<0) return -x;
	return x;
}
int f(int x1,int x2,int y1,int y2){
	int ans=inf;
	ans=min(ans,ab(x1-y1)+ab(x2-y2));
	ans=min(ans,ab(x2-y1)+ab(x1-y2));
	return ans;
}
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=2*n;i++){
		read(a[i]);
		if(!loc[a[i]].first) loc[a[i]].first=i;
		else loc[a[i]].second=i;
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ll ans=f(1,1,loc[1].first,loc[1].second);
	for(i=2;i<=n;i++){
		ans+=f(loc[i-1].first,loc[i-1].second,loc[i].first,loc[i].second);
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}