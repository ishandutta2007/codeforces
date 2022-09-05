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
const int N = 1005;
int n,y[N];
int a[N],b[N];
bool ok,used[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool is_on(int x1, int y1, int x2, int y2) {
	ll tmp=(ll)x1*y2-(ll)x2*y1;
	return tmp==0;
}
bool judge(int k) { //(1,y[1])
	int len=0;
	rep(i,2,n)
		if (k==1||!is_on(i-1,y[i]-y[1],k-1,y[k]-y[1])) {
			a[++len]=i; b[len]=y[i];
		}
	if (len==0) return 0; //!!
	rep(i,3,len)
		if (!is_on(a[i]-a[1],b[i]-b[1],a[2]-a[1],b[2]-b[1])) return 0;
	a[len+1]=a[len]; b[len+1]=b[len];
	return (is_on(k-1,y[k]-y[1],a[2]-a[1],b[2]-b[1]));
}
bool j1() {
	int k=2;
	rep(i,3,n)
		if (!is_on(i-1,y[i]-y[1],k-1,y[k]-y[1])) return 0;
	return 1;
}
int main() {
	read(n); rep(i,1,n) read(y[i]);
	rep(i,1,n) ok|=judge(i);
	if (j1()) ok=0;
	printf("%s",ok ? "Yes" : "No");
	return 0;
}