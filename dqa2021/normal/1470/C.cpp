#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
/*
typedef pair<int,int> P;
*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)
typedef unsigned uint;
uint getrand(){
	static uint sd=987246148U;
	return sd^=sd>>13,sd^=sd<<28,sd^=sd>>22,sd^=sd<<9;
}

int n,k;
int ask(const int &x){
	static int cnt=0;
	++cnt; assert(cnt<=1000);
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
void solve(){
//	srand(time(0));
	n=read(),k=read();
	int pos,tot=0,w;
	while (1){
		pos=getrand()%n+1; tot++;
		if ((w=ask(pos))!=k) break;
	}
	if (w<k){
		for (int i=18;~i;i--)
			if (tot>=(1<<i)){
				int _pos=(pos+(1<<i)-1)%n+1;
				if (ask(_pos)<=k) pos=_pos;
			}
	}
	else{
		for (int i=18;~i;i--)
			if (tot>=(1<<i)){
				int _pos=((pos-(1<<i)-1)%n+n)%n+1;
				if (ask(_pos)>=k) pos=_pos;
			}
	}
	printf("! %d\n",pos);
	fflush(stdout);
}
int main()
{
	for (int T=1;T--;) solve();
}