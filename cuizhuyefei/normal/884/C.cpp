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
const int N = 100200;
int n,p[N];
int size[N],len;
bool vis[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) read(p[i]);
	rep(i,1,n) if (!vis[i]) {
		int cnt=0,u=i;
		while (!vis[u]) vis[u]=1,cnt++,u=p[u];
		size[++len]=cnt;
	}
	sort(size+1,size+len+1);
	if (len==1) printf("%lld",(ll)n*n);
	else {
		ll ans=0;
		rep(i,1,len-2) ans+=(ll)size[i]*size[i];
		printf("%lld",ans+(ll)(size[len]+size[len-1])*(size[len]+size[len-1]));
	}
	return 0;
}