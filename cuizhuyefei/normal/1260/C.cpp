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
inline char read() {
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
        if (s == t) return -1;
    }
    return *s++;
}
template<class T>
inline void read(T &x) {
    static bool iosig;
    static char c;
    for (iosig = false, c = read(); !isdigit(c); c = read()) {
        if (c == '-') iosig = true;
        if (c == -1) return;
    }
    for (x = 0; isdigit(c); c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    if (iosig) x = -x;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int a[N],sz;
int solve(int p1, int p2){
	sz=0;int res=0;
	rep(i,1,p1/gcd(p1,p2)*p2)
		if(i%p1==0&&i%p2==0)a[++sz]=1;
		else if(i%p1==0)a[++sz]=0;else if(i%p2==0)a[++sz]=1;
	rep(i,1,sz){
		int j=i;while(j+1<=sz&&a[j+1]==a[i])j++;
		umax(res,j-i+1);
	}
	return res;
}
int main() {
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	/*int p1=7,p2=9;
	rep(i,1,p1/gcd(p1,p2)*p2*2+1)
		if(i%p1==0&&i%p2==0)a[++sz]=2;
		else if(i%p1==0)a[++sz]=0;else if(i%p2==0)a[++sz]=1;
	rep(i,1,sz)printf("%d",a[i]);*/
	/*rep(p1,1,200)rep(p2,p1,200)if(solve(p1,p2)!=(p1!=p2?(p2-1-gcd(p1,p2))/p1+1:1)){
		printf("%d %d %d\n",p1,p2,solve(p1,p2));
		return 0;
	}*/
//	int g;rep(p1,1,200)rep(p2,p1,200)if(g=gcd(p1,p2)>1)assert(solve(p1,p2)==solve(p1/g,p2/g));
//	rep(p1,1,5)rep(p2,p1,5)printf("%d %d:%d\n",p1,p2,(p1!=p2?(p2-1-gcd(p1,p2))/p1+1:1));
	int T;read(T);while(T--){
		int p1,p2,k;read(p1);read(p2);read(k);
		if(p1>p2)swap(p1,p2);
		printf("%s\n",((p1!=p2?(p2-1-gcd(p1,p2))/p1+1:1)<k)?"OBEY":"REBEL");
	}
	return 0;
}