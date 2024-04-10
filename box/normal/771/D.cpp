// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int cn[3];
int iv[3][75],ps[3][75];
int dp[75][75][75][3];

int dfs(int x,int y,int z,int i){
	if(!(x+y+z))return 0;
	int c=(i==0)?x:((i==1)?y:z);
	int ld=ps[i][c-1];
	if(!c)return 1e9;
	int g=0;
	if(x&&ps[0][x-1]>ld)g+=x-iv[0][ld];
	if(y&&ps[1][y-1]>ld)g+=y-iv[1][ld];
	if(z&&ps[2][z-1]>ld)g+=z-iv[2][ld];
	// cout<<x<<' '<<y<<' '<<z<<' '<<i<<' '<<ld<<' '<<g<<' '<<iv[2][ld]<<endl;
	if(dp[x][y][z][i]!=-1)return dp[x][y][z][i];
	int X=x-(i==0),Y=y-(i==1),Z=z-(i==2);c=1e9;
	rep(j,3)if(i!=2||j!=1)c=min(c,dfs(X,Y,Z,j));
	return dp[x][y][z][i]=c+g;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
	rep(i,n){
		char c;cin>>c;
		if(c=='V')iv[1][i]++,ps[1][cn[1]++]=i;
		else if(c=='K')iv[2][i]++,ps[2][cn[2]++]=i;
		else iv[0][i]++,ps[0][cn[0]++]=i;
	}
	rep1(i,n-1)rep(j,3)iv[j][i]+=iv[j][i-1];
	// rep(i,n)rep(j,3)iv[j][i]=cn[j]-iv[j][i];
	memset(dp,-1,sizeof dp);
	int x=1e9;
	rep(i,3)x=min(x,dfs(cn[0],cn[1],cn[2],i));
	cout<<x<<endl;
}