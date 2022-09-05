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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 555555;
int n,m,a[N],b[N];ll res;
int main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,m)read(b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	if(a[n]>b[1]){puts("-1");return 0;}
	rep(i,1,n)res+=1LL*a[i]*m;
	rep(i,1,m)res+=b[i]-((i==1&&b[1]>a[n])?a[n-1]:a[n]);
	cout<<res;
	return 0;
}