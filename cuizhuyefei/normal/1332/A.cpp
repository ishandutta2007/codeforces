#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

bool ck(int x, int l, int r, int a, int b){
	if(l==r&&a)return 0;
	if(x+b-a>r||x+b-a<l)return 0;
	return 1;
}
int main() {
	int T;read(T);while(T--){
		int a,b,c,d,x,y,x1,y1,x2,y2;
		read(a);read(b);read(c);read(d);
		read(x);read(y);read(x1);read(y1);read(x2);read(y2);
		printf("%s\n",ck(x,x1,x2,a,b)&&ck(y,y1,y2,c,d)?"Yes":"No");
	}
	return 0;
}