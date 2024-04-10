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
const int N = 200004;
int n,a[N],ans[N];
struct TG {
	int v,ind;
} b[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(TG x, TG y) {
	return x.v>y.v;
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n) read(b[i].v),b[i].ind=i;
	sort(b+1,b+n+1,cmp);
	rep(i,1,n) ans[b[i].ind]=a[i];
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}