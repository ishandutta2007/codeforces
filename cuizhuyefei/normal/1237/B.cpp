#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int v[N],a[N],b[N],pos[N],n,res;
void modify(int p){while(p<=n)v[p]++,p+=p&-p;}
int qry(int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	reverse(a+1,a+n+1);reverse(b+1,b+n+1);
	rep(i,1,n)pos[b[i]]=i;
	per(i,n,1){
		res+=qry(pos[a[i]])>0;
		modify(pos[a[i]]);
	}
	cout<<res;
	return 0;
}