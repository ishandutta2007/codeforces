#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
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
const int N = 200300;
int n,m,a[N],v[N],sum[N];
ll ans;
map<int,int> rec;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
struct ST {
	int v[N][19],log2[N],n;
	inline void init(int x) { //st.v[i][0] has numbers!
		n=x; log2[1]=0; rep(i,2,n) {log2[i]=log2[i-1]; if ((1<<log2[i]+1)<=i) log2[i]++;}
		rep(i,1,n) v[i][0]=a[i];
		rep(j,1,log2[n])
			rep(i,1,n-(1<<j)+1)
				v[i][j]=max(v[i][j-1],v[i+(1<<(j-1))][j-1]);
	}
	inline int query(int l, int r) {
		int k=log2[r-l+1];
		return max(v[l][k],v[r-(1<<k)+1][k]);
	}
} st;
struct ST1 {
	int v[N][19],log2[N],n;
	inline void init(int x) { //st.v[i][0] has numbers!
		n=x; log2[1]=0; rep(i,2,n) {log2[i]=log2[i-1]; if ((1<<log2[i]+1)<=i) log2[i]++;}
		rep(i,1,n) v[i][0]=a[i];
		rep(j,1,log2[n])
			rep(i,1,n-(1<<j)+1)
				v[i][j]=(v[i][j-1]|v[i+(1<<(j-1))][j-1]);
	}
	inline int query(int l, int r) {
		int k=log2[r-l+1];
		return (v[l][k]|v[r-(1<<k)+1][k]);
	}
} st1;

int main() {
	read(n); rep(i,1,n) read(a[i]);
	st.init(n); st1.init(n); //st.init()!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	rep(i,1,n) {
		int l=i,r=i; int pre=rec[a[i]]+1;
		per(j,18,0) if (l-(1<<j)>=pre && st.query(l-(1<<j),l-1)<=a[i]) {
			int tmp=st1.query(l-(1<<j),l-1); if ((a[i]&tmp)==tmp) l-=(1<<j);
		}
		per(j,18,0) if (r+(1<<j)<=n && st.query(r+1,r+(1<<j))<=a[i]) {
			int tmp=st1.query(r+1,r+(1<<j)); if ((a[i]&tmp)==tmp) r+=(1<<j);
		}
		ans+=(ll)(r-i+1)*(i-l+1); rec[a[i]]=i;
	//	printf("%d %d %d\n",i,l,r);
	}
	printf("%lld",(ll)n*(n+1)/2-ans);
	return 0;
}
/*
per(i,18,0)
 
*/