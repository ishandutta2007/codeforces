#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
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
int n,x,y,a,b;
int ask(int x){
	printf("? %d\n",x);fflush(stdout);
	int y;read(y);return y;
}
int Win(int x){printf("! %d\n",x);fflush(stdout);exit(0);}
int main() {
	read(n);int l=2,r=n/2;if(n%4==2)Win(-1);
	x=ask(1),y=ask(1+n/2);if(x==y)Win(1);
	while(l<=r){
		int mid=(l+r)>>1;
		a=ask(mid);b=ask(mid+n/2);if(a==b)Win(mid);
		if((x<y)^(a<b))r=mid-1;else l=mid+1;
	}
	Win(-1);
	return 0;
}