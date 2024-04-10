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
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 6666;
int n;Vi a,b;
bool cmp(int x, int y){
	printf("? %d %d\n",x,y);fflush(stdout);
	string c;cin>>c;return c[0]=='<';
}
int findmin(Vi a){
	int x=a[0];
	rep(i,1,SZ(a)-1)if(cmp(a[i],x))x=a[i];return x;
}
void era(Vi &a, int x){
	rep(i,0,SZ(a)-1)if(a[i]==x){
		a.erase(a.begin()+i);break;
	}
}
int main() {
	int T;read(T);while(T--){
		read(n);a.clear();b.clear();
		a={1};rep(i,2,n)b.pb(i);
		rep(i,n+1,2*n){
			if(SZ(a)<SZ(b))a.pb(i);else b.pb(i);
			assert(SZ(a)<n&&SZ(b)<n);
			int x=findmin(a),y=findmin(b);
			if(cmp(x,y))era(a,x);else era(b,y);
		}
		printf("!\n");fflush(stdout);
	}
	return 0;
}