#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)
typedef unsigned long long ull;
ull getrand(){
	static ull sd=987123475942569741ULL;
	return sd^=sd>>7,sd^=sd<<43,sd^=sd>>34,sd^=sd<<22;
}


ull x; const ull lim=2e18;

struct C{
	ull x; int o; ull y;  //0 ^ 1 +
}; vector<C> S;
void ins(ull x,int o,ull y){
	S.pb((C){x,o,y});
}

void mul(ull x,ull y){
	if (y==1) return;
	mul(x,y>>1);
	ull z=x*(y>>1);
	ins(z,1,z); z+=z;
	if (y&1) ins(z,1,x);
}

ull lb[64];
vector<ull> T[64];
vector<ull> get(vector<ull> W){
	map<ull,int> mp;
	vector<ull> res;
	for (auto x: W) mp[x]^=1;
	for (auto x: mp) if (x.se) res.pb(x.fi);
	return res;
}
bool ins(ull x){
	vector<ull> W;
	W.pb(x);
	per(i,0,63)
		if (x>>i&1){
			if (lb[i]){
				x^=lb[i];
				for (auto x: T[i]) W.pb(x);
			}
			else{
				T[i]=get(W);
				lb[i]=x; break;
			}
		}
	return lb[0];
}
void get(){
	ull W=T[0].back();
	ins(W,0,W); W=0;
	for (auto x: T[0]) ins(W,0,x),W^=x;
}

void solve(){
	x=read();
	while (1){
		ull T=getrand()%(lim/x)+1;
		mul(x,T);
		T*=x;
		if (ins(T)) break;
	}
	get();
	printf("%d\n",int(S.size()));
	for (auto x: S) printf("%llu %c %llu\n",x.x,"^+"[x.o],x.y);
}
int main()
{
	for (int T=1;T--;) solve();
}