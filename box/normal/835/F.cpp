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

int n;
vector<pair<int,ll>> elist[200005];
bool onCyc[200005];
ll maxdis[200005];

int tdeg[200005];

ll V[400005],W[400005];

struct tag{
	ll mxan,mxV,mxW;
	const tag operator+(const tag& o)const {return {max(max(mxan,o.mxan),mxV+o.mxW),max(mxV,o.mxV),max(mxW,o.mxW)};}
}seg[400005<<2];
#define lson idx*2,l,(l+r)/2
#define rson idx*2+1,(l+r)/2,r
tag bld(int idx,int l,int r){if(r-l==1)return seg[idx]={-(1ll<<60),V[l]+W[l],V[l]-W[l]};return seg[idx]=bld(lson)+bld(rson);}
tag qry(int idx,int l,int r,int L,int R){
	if(L<=l&&r<=R)return seg[idx];
	if(R<=l||r<=L)return {-(1ll<<60),-(1ll<<60),-(1ll<<60)};
	return qry(lson,L,R)+qry(rson,L,R);}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n;gi(n);
	ll ans=1e18,LQ=0;
	rep1(i,n){
		int u,v,w;gi(u),gi(v),gi(w);
		elist[u].push_back({v,w});
		elist[v].push_back({u,w});
	}
    queue<int>q;
	rep1(i,n)onCyc[i]=1;
	rep1(u,n)for(auto[v,w]:elist[u])tdeg[v]++;
	rep1(u,n)if(tdeg[u]==1){
		onCyc[u]=0;
		maxdis[u]=0;
		q.push(u);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto[v,w]:elist[u]){
			if(!onCyc[v])continue;
			tdeg[v]--;if(tdeg[v]==1){
				onCyc[v]=0;
				q.push(v);
			}
			LQ=max(LQ,maxdis[u]+w+maxdis[v]);
			maxdis[v]=max(maxdis[v],maxdis[u]+w);
		}
	}
	int c=-1;
	rep1(i,n)if(onCyc[i])c=i;
	int f=-1,u=c,idx=0;
	while(f==-1||u!=c){
		if(f==u)break;
		for(auto[v,w]:elist[u])if(v!=f&&onCyc[v]){
			V[idx]=maxdis[u];W[idx]=w;idx++;
			f=u;u=v;break;
		}
	}
	int N=idx;
	rep(i,N)V[i+N]=V[i],W[i+N]=W[i];
	for(int i=2*N-1;i>=0;i--)W[i]+=W[i+1];
	bld(1,0,2*N);
	rep(i,N)ans=min(ans,max(LQ,qry(1,0,2*N,i,i+N).mxan));
	cout<<ans<<endl;
}