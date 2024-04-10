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
const int N = 533333;
int n,a[N];
int main() {
	read(n);rep(i,1,n*2)read(a[i]);sort(a+1,a+n*2+1);
	ll res=1LL*(a[n]-a[1])*(a[n+n]-a[n+1]);
	rep(i,1,n)res=min(res,1LL*(a[n+n]-a[1])*(a[i+n-1]-a[i]));
	cout<<res;
	return 0;
}