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
const int N = 10050;
int n,T,a[N],dp[N],buc[305];

inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int getans() {
	int ans=0;
	rep(i,1,n*n) {
		if (a[i]>=dp[ans]) dp[++ans]=a[i];
		else *(upper_bound(dp+1,dp+ans+1,a[i]))=a[i];
		if (i==n*T) return ans;
	}
	int mx=0;
	rep(i,1,n) buc[a[i]]++,mx=max(mx,buc[a[i]]);
	return ans+mx*(T-n);
}
int main() {
	read(n); read(T); rep(i,1,n) read(a[i]);
	rep(i,n+1,n*n) a[i]=a[i-n];
	printf("%d",getans());
	return 0;
}