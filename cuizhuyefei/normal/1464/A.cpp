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
const int N = 1e5+11;
int n,m,a[N];
int main() {
	int T;read(T);while(T--){
		read(n);read(m);
		rep(i,1,n)a[i]=0;int res=0;
		rep(i,1,m){
			int x,y;read(x);read(y);
			if(x!=y)a[x]=y,res++;
		}
		rep(i,1,n)if(a[i]){
			Vi b;
			for(int j=a[i];j;j=a[j]){b.pb(j);if(j==i)break;}
			if(b.back()==i)res++;
			for(int x:b)a[x]=0;
		}
		cout<<res<<endl;
	}
	return 0;
}