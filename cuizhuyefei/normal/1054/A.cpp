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
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
ll x,y,z,t1,t2,t3,a1,a2;
ll Abs(ll x){return x>0?x:-x;}
int main() {
	read(x);read(y);read(z);
	read(t1);read(t2);read(t3);
	a1=t2*(Abs(x-z)+Abs(x-y))+3*t3;
	a2=Abs(x-y)*t1;
	
	if(a1<=a2)puts("YES");else puts("NO");
	return 0;
}