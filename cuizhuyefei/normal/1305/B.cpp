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
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int sta[N],top,n;Vi a,b;char s[N];
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n)if(s[i]=='(')a.pb(i);
	per(i,n,1)if(s[i]==')')b.pb(i);
	int x=0;
	for(int c=1;c<=n;c++)if(SZ(a)>=c&&SZ(b)>=c&&a[c-1]<b[c-1]){
		x=c;
	}
	int c=x;
	if(!c){puts("0");return 0;}
	printf("1\n");
	Vi d;rep(i,0,c-1)d.pb(a[i]),d.pb(b[i]);sort(ALL(d));
	printf("%d\n",SZ(d));for(int x:d)printf("%d ",x);
	return 0;
}