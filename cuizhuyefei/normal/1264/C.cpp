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
const int N = 1<<18|3, mo = 998244353, inv2 =(mo+1)/2;
const ll MOD=7LL*mo*mo;
bool mrk[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
set<int>Set;
int n,q,p[N],qz[N],sum[N];
int qry(int l, int r){
	return 1ll*(sum[r-2]-(l-2>=0?sum[l-2]:0)+mo)*power(qz[l-1],mo-2)%mo*power(qz[r-1],mo-2)%mo*qz[l-1]%mo;
}
int main() {
	read(n);read(q);rep(i,1,n)read(p[i]),p[i]=1ll*p[i]*power(100,mo-2)%mo;
	qz[0]=1;rep(i,1,n)qz[i]=1ll*qz[i-1]*p[i]%mo;
	sum[0]=qz[0];rep(i,1,n)sum[i]=(sum[i-1]+qz[i])%mo;
	Set.insert(1);Set.insert(n+1);int res=qry(1,n+1);
	while(q--){
		int u;read(u);
		if(!Set.count(u)){
			auto y=Set.upper_bound(u),x=y;x=y;x--;
			sub(res,qry(*x,*y));add(res,qry(*x,u));add(res,qry(u,*y));
			Set.insert(u);
		}
		else{
			Set.erase(u);auto y=Set.upper_bound(u),x=y;x=y;x--;
			add(res,qry(*x,*y));sub(res,qry(*x,u));sub(res,qry(u,*y));
		}
		printf("%d\n",res);
	}
	/*cout<<qry(1,n+1)<<endl;
	cout<<1ll*qry(1,2)%mo<<endl;
	cout<<1ll*qry(1,2)+qry(2,n+1)%mo<<endl;*/
	return 0;
}