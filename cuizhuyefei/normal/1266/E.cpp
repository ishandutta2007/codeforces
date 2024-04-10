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
int n,q,a[N];ll res;
map<Pii,int>Map;
int main() {
	read(n);rep(i,1,n)read(a[i]),res+=a[i];
	read(q);while(q--){
		int s,t,u;read(s);read(t);read(u);
		if(Map.count(Pii(s,t))){
			int u=Map[Pii(s,t)];if(a[u]>=0)res++;a[u]++;
			Map.erase(Pii(s,t));
		}
		if(u){
			if(a[u]>=1)res--;a[u]--;
			Map[Pii(s,t)]=u;
		}
		printf("%lld\n",res);
	}
	return 0;
}