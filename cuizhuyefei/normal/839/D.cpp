#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 1000003, mo = 1000000007;
int n,ans[N],cnt[N],po[N];

inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	int mx=0;
	read(n); int x; rep(i,1,n) read(x),cnt[x]++,mx=max(mx,x);
	po[0]=1; rep(i,1,mx) {po[i]=po[i-1]<<1; if (po[i]>=mo) po[i]-=mo;}
	int res=0;
	per(i,mx,2) { //maxv
		int x=0; for (int j=i; j<=mx; j+=i) x+=cnt[j];
		ans[i]=(ll)x*po[x-1]%mo;
		for (int j=i+i; j<=mx; j+=i) (ans[i]+=(mo-ans[j]))%=mo;
		res+=(ll)ans[i]*i%mo; if (res>=mo) res-=mo;
	//	printf("%d %d\n",i,ans[i]);
	}
	printf("%d",res);
	return 0;
}