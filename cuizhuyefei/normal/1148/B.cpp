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
ll n,m,t1,t2,k,a[N],b[N];ll res;
int main() {
	read(n);read(m);read(t1);read(t2);read(k);
	if(k>=n||k>=m){puts("-1");return 0;}
	rep(i,1,n)read(a[i]),a[i]+=t1;
	rep(i,1,m)read(b[i]);
	for(int i=1,j=0;i<=n;i++)if(i-1<=k){
		while(j+1<=m&&b[j+1]<a[i])j++;
		if(j+k-(i-1)+1>m){puts("-1");return 0;}
		umax(res,t2+b[j+k-(i-1)+1]);
	}
	cout<<res;
	return 0;
}