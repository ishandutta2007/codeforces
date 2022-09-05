
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
const int N = 10200, mo = 1e9+7;
int n,ans=1e9,l1=1e9,r1=-1e9,l2=1e9,r2=-1e9,ans1=1e9,ans2=1e9; //min = -inf!!
struct dot {
	int x,y;
	dot(int X=0, int Y=0) {x=X; y=Y;}
} s[N];
int Abs(int x) {return x>0?x:-x;}
int dis(dot a, dot b){return max(Abs(a.x-b.x),Abs(a.y-b.y));}
inline void getans(int &ans, dot x, dot y) {
	ans=0; rep(i,1,n) ans=max(ans,min(dis(x,s[i]),dis(y,s[i])));
}
bool ck() {
	if (ans1!=ans2) return 0;
	rep(i,1,n) if (s[i].y>l2+ans||s[i].y<r2-ans) return 1;
	return 0;
}
int main() {
	read(n); rep(i,1,n) {
		int x,y;read(x),read(y); s[i].x=x+y; s[i].y=x-y;
	//	printf("<%d,%d>\n",s[i].x,s[i].y);
		l1=min(l1,s[i].x); r1=max(r1,s[i].x);
		l2=min(l2,s[i].y); r2=max(r2,s[i].y);
	}
	getans(ans1,dot(l1,l2),dot(r1,r2));
	getans(ans2,dot(l1,r2),dot(r1,l2)); ans=min(ans1,ans2);
	cout<<ans<<endl; int res=2;
	rep(i,1,n) if (s[i].x>=r1-ans&&s[i].x<=l1+ans&&s[i].y>=r2-ans&&s[i].y<=l2+ans) res=res*2%mo;
	if (ck()) res=res*2%mo;
	cout<<res;
	return 0;
}