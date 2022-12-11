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
#define all(x) (x).begin(),(x).end()

int n;
void solve(){
	n=read();
	vector<int> S,T;
	rep(i,1,n<<1){
		int x=read(),y=read();
		if (!x) S.pb(abs(y));
		else T.pb(abs(x));
	}
	sort(all(S)); sort(all(T));
	double ans=0;
	rep(i,0,S.size()-1) ans+=sqrt(1.0*S[i]*S[i]+1.0*T[i]*T[i]);
	printf("%.10lf\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}