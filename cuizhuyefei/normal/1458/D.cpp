#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
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
template<class T> inline T Abs(const T &x){return x>0?x:-x;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 5e5+11;
char s[N];int n,P[N<<2];
int *a=P+N,*b=P+3*N;
int main() {
	int T;read(T);while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,-n,n)a[i]=b[i]=0;int x=0;
		rep(i,1,n){if(s[i]=='0')a[x]++;else b[x]++;x+=s[i]=='0'?-1:1;}
		x=0;while(a[x]||b[x]){
			if(a[x]&&!(a[x]==1&&!b[x-1]&&b[x]))a[x]--,x--,putchar('0');
			else b[x]--,x++,putchar('1');
		}
		puts("");
	}
	return 0;
}