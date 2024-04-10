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
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
int query(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout); int x; scanf("%d",&x); return x;
}
void win(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
	printf("! %d %d %d %d %d %d %d %d\n",x1,y1,x2,y2,X1,Y1,X2,Y2);
	fflush(stdout); exit(0);
}
void getans(int l1, int l2, int r1, int r2, int &x1, int &y1, int &x2, int &y2) {
	ll L,R,res;
	L=l1; R=r1; res=0;
	while (L<=R) {
		ll mid=(L+R)>>1; int tmp=query(mid,l2,r1,r2);
		if (tmp==1) {res=mid; L=mid+1;} else R=mid-1;
	}
	x1=res;
	L=l1; R=r1; res=0;
	while (L<=R) {
		ll mid=(L+R)>>1; int tmp=query(l1,l2,mid,r2);
		if (tmp==1) {res=mid; R=mid-1;} else L=mid+1;
	}
	x2=res;	
	L=l2; R=r2; res=0;
	while (L<=R) {
		ll mid=(L+R)>>1; int tmp=query(l1,mid,r1,r2);
		if (tmp==1) {res=mid; L=mid+1;} else R=mid-1;
	}
	y1=res;	
	L=l2; R=r2; res=0;
	while (L<=R) {
		ll mid=(L+R)>>1; int tmp=query(l1,l2,r1,mid);
		if (tmp==1) {res=mid; R=mid-1;} else L=mid+1;
	}
	y2=res;
}
int main() {
	ll n; read(n);
	ll l=1,r=n,res=0;
	while (l<=r) {
		ll mid=(l+r)>>1; int tmp=query(1,1,mid,n);
		if (tmp==1) {res=mid; r=mid-1;}
		else if (tmp<1) {l=mid+1;} else r=mid-1;
	}
	if (res&&res<n&&query(1,1,res,n)==1&&query(res+1,1,n,n)==1) {
		int x1,y1,x2,y2,X1,Y1,X2,Y2;
		getans(1,1,res,n,x1,y1,x2,y2);
		getans(res+1,1,n,n,X1,Y1,X2,Y2);
		win(x1,y1,x2,y2,X1,Y1,X2,Y2);
	}
	l=1; r=n; res=0;
	while (l<=r) {
		ll mid=(l+r)>>1; int tmp=query(1,1,n,mid);
		if (tmp==1) {res=mid; r=mid-1;}
		else if (tmp<1) l=mid+1; else r=mid-1;
	}
	if (1) {
		int x1,y1,x2,y2,X1,Y1,X2,Y2;
		getans(1,1,n,res,x1,y1,x2,y2);
		getans(1,res+1,n,n,X1,Y1,X2,Y2);
		win(x1,y1,x2,y2,X1,Y1,X2,Y2);
	}	
	return 0;
}