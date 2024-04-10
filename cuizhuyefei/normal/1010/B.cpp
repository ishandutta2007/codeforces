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
int m,n,a[66];
int ask(int x){
	printf("%d\n",x);fflush(stdout);
	int r;read(r);if(!r)exit(0);return r;
}
int main() {
	read(m);read(n);
	rep(i,1,n)a[i]=ask(1);
	int l=2,r=m,cnt=0;
	while(l<=r){
		int mid=(l+r)>>1;int t=ask(mid);cnt++;cnt=cnt>n?cnt-n:cnt;
		if(t==a[cnt])l=mid+1;else r=mid-1;
	}
	return 0;
}