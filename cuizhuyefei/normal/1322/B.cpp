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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 444444;
int n,a[N],b[N],id[N],s[N],res;
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)id[i]=i;
	rep(j,0,24){
		//id[1..n]
		ll cur=0;int cnt=0;rep(i,1,n)if(!(a[id[i]]>>j&1))cnt++;
		int all=(1<<j)-1;
		cur=1ll*cnt*(n-cnt);
		for(int i=1,x=n+1;i<=n;i++){
			while(x-1>=1&&(a[id[i]]&all)+(a[id[x-1]]&all)>all)x--;
			cur+=n-max(i+1,x)+1;
		}
		
		if(cur&1)res^=1<<j;
		
		int sz=0;rep(i,1,n)if(!(a[id[i]]>>j&1))s[++sz]=id[i];
		rep(i,1,n)if((a[id[i]]>>j&1))s[++sz]=id[i];
		rep(i,1,n)id[i]=s[i];
	}
	cout<<res;
	return 0;
}