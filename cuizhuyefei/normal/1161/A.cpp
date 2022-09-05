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
const int N = 233333;
int n,k,a[N],res,mx[N],mn[N];bool vis[N];
bool ck(int x, int y){
	return mx[y]<mn[x];
}
int main() {
	read(n);read(k);rep(i,1,k)read(a[i]);
	rep(i,1,n)mx[i]=0,mn[i]=k+1;
	rep(i,1,k)vis[a[i]]=1,umax(mx[a[i]],i),umin(mn[a[i]],i);
	rep(i,1,n)res+=!vis[i];
	rep(i,1,n-1)res+=ck(i,i+1);
	rep(i,2,n)res+=ck(i,i-1);
	
	cout<<res;
	return 0;
}