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
typedef pair<ll,ll> Pii;
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
const int N = 303000;
int l,r,m;Pii sta[N];int top;ll k,b;
Pii operator-(Pii a, Pii b){return Pii(a.fi-b.fi,a.se-b.se);}
double Cross(Pii a, Pii b){
	return 1.0*a.fi*b.se-1.0*a.se*b.fi;
}
ll calc(Pii a){return 1LL*k*a.fi+a.se+b;}
int main() {
	l=1;read(r);read(m);sta[++top]=Pii(1,0);
	while(m--){
		int op;read(op);
		if(op==1){
			int x;read(x);l-=x;
			k=b=0;top=1;sta[top]=Pii(l,0);
		}
		else if(op==2){
			int x;read(x);Pii c=Pii(r+1,-1LL*k*(r+1)-b);
			while(top>1&&Cross(sta[top]-sta[top-1],c-sta[top])<=0)top--;
			sta[++top]=c;r+=x;
		}
		else{
			int B,s;read(B);read(s);
			k+=s;b+=B-1LL*l*s;
		}
		while(top>1&&calc(sta[top])>=calc(sta[top-1]))top--;
		printf("%lld %lld\n",sta[top].fi-l+1,calc(sta[top]));
	}
	return 0;
}