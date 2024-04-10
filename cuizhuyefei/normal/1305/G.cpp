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
const int N = 1<<18|3;
int n,a[N],f[N],sz[N];Pii seg[N];ll res;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x, int y, int z){x=find(x);y=find(y);if(x!=y){if(sz[x]>sz[y])swap(x,y);sz[y]+=sz[x];f[x]=y,res+=z;}}
int main() {
	read(n);rep(i,1,n)read(a[i]),res-=a[i];a[++n]=0;
	sort(a+1,a+n+1);
	rep(i,0,1<<18)seg[i].fi=n+1;
	rep(i,1,n)seg[a[i]].se=i;
	per(i,n,1)seg[a[i]].fi=i;
	rep(i,1,n)f[i]=i,sz[i]=1;
	per(i,1<<18,0)for(int j=i;j*2>i;j=(j-1)&i){
		if(seg[j].fi<=seg[j].se&&seg[i^j].fi<=seg[i^j].se){
			rep(x,seg[j].fi,seg[j].fi)rep(y,seg[i^j].fi,seg[i^j].se)merge(x,y,i);
			rep(x,seg[i^j].fi,seg[i^j].fi)rep(y,seg[j].fi,seg[j].se)merge(x,y,i);
			seg[j].se=seg[j].fi;seg[i^j].se=seg[i^j].fi;
		}
	}
	cout<<res;
	return 0;
}