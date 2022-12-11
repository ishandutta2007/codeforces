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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,d,a[110];
void solve(){
	n=read(),d=read();
	rep(i,1,n) a[i]=read();
	while (d){
		int pos=-1;
		rep(i,2,n){
			if (a[i]){
				pos=i; break;
			}
		}
		if (!~pos) break;
		if (pos-1>d) break;
		a[pos]--,a[1]++; d-=pos-1;
	}
	printf("%d\n",a[1]);
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}