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
const double eps = 1e-9;
const int N = 133, inf = 0x3f3f3f3f;
int n,a[N][7],c[23],v[23],now,cnt[N];
int f[N][15005];
int A[]={0,2,4,8,16,32};
void umin(int &a, int b) {a=a<b?a:b;}
int getscore(int x, int y) {
	double p=1.0*x/y;
	if (p>1.0/2) return 500;
	if (p>1.0/4) return 1000;
	if (p>1.0/8) return 1500;
	if (p>1.0/16) return 2000;
	if (p>1.0/32) return 2500;
	return 3000;
}
int calc(int a, int b, int x, int y) { // score = a/b, time = x/y
	return int(getscore(a,b)/250)*((x==-1?0:(250-x))-(y==-1?0:(250-y)));
}
int Get(int x, int y) {
	if (x==-1&&y==-1) return 0;
	int len=0;
	if (x>=0&&y==-1||x>=0&&y>=0&&x<y) { //X
		rep(i,1,5) {
			int p=now*A[i]-n;
			if (p>0) {c[++len]=p; v[len]=calc(now,n+p,x,y)-calc(now,n,x,y);}
		}
		return len;
	}
	if (x>=0&&y>=0&&x>y) { //J
		rep(i,1,5) {
			int p=(n-now*A[i]-1)/(A[i]-1)+1;
			if (p>0) {c[++len]=p; v[len]=calc(now+p,n+p,x,y)-calc(now,n,x,y);}
		}
		return len;
	}
	return 0;
}
bool ck(int ans) {
	int res=0;
	rep(i,1,5) {
		res+=max(calc(cnt[i],ans,a[1][i],a[2][i]),a[1][i]>=0?calc(cnt[i]+ans-n,ans,a[1][i],a[2][i]):-inf);
	//	printf("%d : %d\n",i+1,max(calc(cnt[i],ans,a[1][i],a[2][i]),calc(cnt[i]+ans-n,ans,a[1][i],a[2][i])));
	}
	return res>0;
}
int main() { //freopen("1.in","r",stdin);
	read(n);rep(i,1,n)rep(j,1,5)read(a[i][j]),cnt[j]+=a[i][j]>=0;
	rep(i,n,400000) if (ck(i)) {printf("%d",i-n); return 0;}
	puts("-1");
	return 0;
}