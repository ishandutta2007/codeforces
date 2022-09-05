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
int n,m;
void print(int x, int y){printf("%d %d\n",x,y);}
void yzr(int x, int y){
	rep(i,1,m)print(x,i),print(y,m-i+1);
}
int main() {
	read(n);read(m);
	rep(i,1,n/2)if(i<n-i+1)yzr(i,n-i+1);
	if(n&1){
		int x=(n+1)/2;
		rep(i,1,m/2)if(i<m-i+1)print(x,i),print(x,m-i+1);
		if(m&1)print(x,(m+1)/2);
	}
	return 0;
}