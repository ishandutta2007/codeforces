#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 600000, inf = 0x3f3f3f3f;
int n,A[N],B[N];
struct dot {
	int x,y;
	dot(int X=0, int Y=0) {x=X; y=Y;}
} s[N];
ll ans;
bool cmp(dot a, dot b) {return a.x!=b.x?a.x<b.x:a.y<b.y;}
int qzmin[N],qzmax[N],hzmin[N],hzmax[N];
inline ll inter(int x, int y, int a, int b) {
	if (x>a) {swap(x,a); swap(y,b);}
	if (a>y) return 0;
	return min(b,y)-a;
}
inline ll solve(int n) {
	sort(s+1,s+n+1,cmp);
	qzmin[0]=inf; qzmax[0]=-inf; hzmin[n+1]=inf; hzmax[n+1]=-inf;
	rep(i,1,n) qzmin[i]=min(qzmin[i-1],s[i].y),qzmax[i]=max(qzmax[i-1],s[i].y);
	per(i,n,1) hzmin[i]=min(hzmin[i+1],s[i].y),hzmax[i]=max(hzmax[i+1],s[i].y);
	ll ans=0;
	rep(i,1,n-1) if (s[i].x!=s[i+1].x) ans+=1LL*(s[i+1].x-s[i].x)*inter(qzmin[i],qzmax[i],hzmin[i+1],hzmax[i+1])>>2;
	return ans;
}
int main() {
	read(n); rep(i,1,n) read(A[i]),read(B[i]);
	int len=0;
	rep(i,1,n) if ((A[i]+B[i])%2==0) s[++len]=dot(B[i]-A[i],B[i]+A[i]);
	ans=solve(len);
	len=0; rep(i,1,n) if ((A[i]+B[i])%2!=0) s[++len]=dot(B[i]-A[i],B[i]+A[i]);
	ans+=solve(len);
	cout<<ans;
	return 0;
}