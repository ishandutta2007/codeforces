#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,m;
struct dot{
	int x,y;
	dot(int X=0,int Y=0){x=X;y=Y;}
	void get(){read(x);read(y);}
}a[N],b[N];
dot operator - (const dot &a, const dot &b){return dot(a.x-b.x,a.y-b.y);}
ll operator * (const dot &a, const dot &b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
inline ll getlen(dot a){return 1LL*a.x*a.x+1LL*a.y*a.y;}
bool cmp(const dot &a, const dot &b){
	ll x=a*b;return x!=0?x>0:getlen(a)<getlen(b);
}
void graham(dot *a, int &n){
	int x=0;rep(i,1,n)x=max(x,a[i].x);
	int y=0;rep(i,1,n)y=max(y,a[i].y);a[++n]=dot(x,0);a[++n]=dot(0,y);
	sort(a+1,a+n+1,cmp);static dot sta[N];int top=0;
	sta[++top]=a[1];sta[++top]=a[2];
	rep(i,3,n){
		while(top>1&&(a[i]-sta[top-1])*(sta[top]-sta[top-1])>=0)top--;
		sta[++top]=a[i];
	}
	n=top;rep(i,1,n)a[i]=sta[i];
}
int main() {
	read(n);read(m);int x;read(x);read(x);
	rep(i,1,n)a[i].get();rep(i,1,m)b[i].get();
	graham(b,m);
	rep(i,1,n){
		int l=1,r=m;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(b[mid]*a[i]>=0)l=mid;else r=mid;
		}
		if((b[r]-b[l])*(a[i]-b[l])<=0){puts("Max");return 0;}
	}
	puts("Min");return 0;
}