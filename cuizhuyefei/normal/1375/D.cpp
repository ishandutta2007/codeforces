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

const int N = 266666;
int n,a[N],vis[N];Vi c;
int qry(){
	rep(i,0,n)vis[i]=0;
	rep(i,1,n)vis[a[i]]=1;
	int x=0;while(vis[x])x++;return x;
}
void ope(int x){
	rep(i,0,n)vis[i]=0;
	rep(i,1,n)vis[a[i]]=1;
	a[x]=0;while(vis[a[x]])a[x]++;
	c.pb(x);
}
int main() {
	int t;read(t);while(t--){
		read(n);rep(i,1,n)read(a[i]);c.clear();
		rep(i,1,n){
			rep(j,1,n)if(a[j]==i-1&&j!=i){
				int x=qry();
				if(x<n&&a[x+1]!=x)ope(x+1),j--;
				else ope(j);
			}
			if(a[i]!=i-1)ope(i);
		}
		rep(i,1,n-1)assert(a[i]<=a[i+1]);
		printf("%d\n",SZ(c));
		for(int x:c)printf("%d ",x);puts("");
	}
	return 0;
}