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
const int N = 333333;
ll n,val[N],msk[N],res;
int main() {
	read(n);
	rep(i,1,n)read(val[i]),read(msk[i]);
	ll s=0;rep(i,1,n)s+=val[i];
	if(s<0){
		rep(i,1,n)val[i]=-val[i];s=-s;
	}
	//s>0 --> s<0
	
	per(bit,62,0){
		ll s=0;rep(i,1,n)if((msk[i]&-msk[i])==(1LL<<bit))s+=val[i];
		if(s>0){
			res|=1LL<<bit;
			rep(i,1,n)if(msk[i]>>bit&1)val[i]=-val[i];
			s=0;rep(i,1,n)if((msk[i]&-msk[i])==(1LL<<bit))s+=val[i];
			assert(s<=0);
		}
	}
	s=0;rep(i,1,n)s+=val[i];assert(s<=0);
	cout<<res;
	return 0;
}