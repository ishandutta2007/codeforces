#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
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
int mx[105],mn=inf;
int sum=0,ans=inf;
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++){
		int x;
		read(x);sum+=x;
		for(j=2;j<=100;j++){
			if(!(x%j)) mx[j]=max(x,mx[j]);
		}
		mn=min(mn,x);
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ans=sum;
	for(i=2;i<=100;i++){
		ans=min(ans,sum-mx[i]+mx[i]/i+mn*(i-1));
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}