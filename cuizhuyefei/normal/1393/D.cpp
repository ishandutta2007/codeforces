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

const int N = 2040;
int n,m,res,d[N][N],u[N][N],l[N][N],r[N][N];char s[N][N];
int main() {
	read(n);read(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)d[i][j]=u[i][j]=l[i][j]=r[i][j]=1e9;
	rep(i,1,n)rep(j,1,m){
		if(j>1)umin(l[i][j],(s[i][j-1]==s[i][j]?l[i][j-1]:0)+1);
		if(i>1)umin(l[i][j],(s[i-1][j]==s[i][j]?l[i-1][j]:0)+1);
	}
	rep(i,1,n)per(j,m,1){
		if(j<m)umin(u[i][j],(s[i][j+1]==s[i][j]?u[i][j+1]:0)+1);
		if(i>1)umin(u[i][j],(s[i-1][j]==s[i][j]?u[i-1][j]:0)+1);
	}
	per(i,n,1)rep(j,1,m){
		if(j>1)umin(d[i][j],(s[i][j-1]==s[i][j]?d[i][j-1]:0)+1);
		if(i<n)umin(d[i][j],(s[i+1][j]==s[i][j]?d[i+1][j]:0)+1);
	}
	per(i,n,1)per(j,m,1){
		if(j<m)umin(r[i][j],(s[i][j+1]==s[i][j]?r[i][j+1]:0)+1);
		if(i<n)umin(r[i][j],(s[i+1][j]==s[i][j]?r[i+1][j]:0)+1);
	}
	rep(i,1,n)rep(j,1,m){
		res+=min({l[i][j],r[i][j],d[i][j],u[i][j],i,n-i+1,j,m-j+1});
	}
	cout<<res;
	return 0;
}