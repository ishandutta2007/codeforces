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
const int N = 2020;
int n,h,a[N],b[N];
bool ck(int n){//b[1..n]
	rep(i,1,n)b[i]=a[i];
	sort(b+1,b+n+1);int now=h;
	for(int i=n;i>=1;)now-=b[i],i-=2;
	return now>=0;
}
int main() {
	read(n);read(h);
	rep(i,1,n)read(a[i]);
	int res=0;rep(i,1,n)if(ck(i))res=i;else break;
	cout<<res;
	return 0;
}