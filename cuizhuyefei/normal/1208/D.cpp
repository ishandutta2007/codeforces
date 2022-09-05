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
const int N = 232000;
int n;ll s[N],v[N];
int p[N];set<int>Set;
inline void add(int p, ll x){
	while(p<=n)v[p]+=x,p+=p&-p;
}
inline ll getqz(int p){
	ll res=0;while(p)res+=v[p],p-=p&-p;return res;
}
int main() {
	read(n);rep(i,1,n)read(s[i]);
	rep(i,1,n)Set.insert(i),add(i,i);
	per(i,n,1){
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(getqz(mid)>=s[i])r=mid;else l=mid+1;
		}
		p[i]=*Set.upper_bound(l);Set.erase(p[i]);add(p[i],-p[i]);
	}
	rep(i,1,n)printf("%d ",p[i]);
	return 0;
}