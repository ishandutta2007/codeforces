#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int a[110][110],n;
void ins(int c,int x,int y){
	a[x][y]=c;
	printf("%d %d %d\n",c,x,y);
	fflush(stdout);
}
void solve(){
	n=read();
	vector<P> S,T;
	rep(i,1,n) rep(j,1,n){
		((i+j)&1?S:T).emplace_back(i,j);
	}
	while (S.size()&&T.size()){
		int c=read();
		if (c==1){
			P v=T.back(); T.pop_back();
			ins(2,v.fi,v.se);
		}
		else{
			P v=S.back(); S.pop_back();
			ins(1,v.fi,v.se);
		}
	}
	while (S.size()){
		int c=read();
		P v=S.back(); S.pop_back();
		if (c==1) ins(3,v.fi,v.se);
		else ins(1,v.fi,v.se);
	}
	while (T.size()){
		int c=read();
		P v=T.back(); T.pop_back();
		if (c==2) ins(3,v.fi,v.se);
		else ins(2,v.fi,v.se);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}