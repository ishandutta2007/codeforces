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

vector<pii>elist[500005];
bool rmv[500005];
int sz[500005];
void dfssz(int u,int f){
	if(rmv[u])return;
	sz[u]=1;
	for(auto[v,w]:elist[u]){
		if(v==f||rmv[v])continue;
		dfssz(v,u);
		sz[u]+=sz[v];
	}
}
pii dfsctr(int u,int f,int x){
	pii ans={1e9,0};
	if(rmv[u])return ans;
	int l=sz[x]-sz[u];
	for(auto[v,w]:elist[u]){
		if(v==f||rmv[v])continue;
		l=max(l,sz[v]);
		ans=min(ans,dfsctr(v,u,x));
	}
	return min(ans,{l,u});
}
int fctr(int ltk){
	assert(!rmv[ltk]);
	dfssz(ltk,-1);return dfsctr(ltk,-1,ltk).second;
}
ll ans=0;
int n,L,W;
int fenw[500005];
void upd(int i,int dt){
	while(i<=n+5){
		fenw[i]+=dt;
		i+=(i&(-i));
	}
}
int qry(int i){
	int ans=0;
	while(i){
		ans+=fenw[i];
		i-=(i&(-i));
	}
	return ans;
}
ll calc(vector<pii>x){
	//{dep,len};
	sort(x.begin(),x.end());
	vector<int>wts;
	for(auto[d,w]:x)wts.push_back(w);
	sort(wts.begin(),wts.end());
	auto idx=[&](int w){return upper_bound(wts.begin(),wts.end(),w)-wts.begin();};
	vector<int>rv;int dr=0;
	auto x2=x;reverse(x2.begin(),x2.end());
	long long vl=0;
	for(auto[d,w]:x2){
		while((dr!=x.size())&&(x[dr].first<=L-d)){
			int re;upd(re=idx(x[dr].se),1);
			rv.push_back(re);dr++;
		}vl+=qry(idx(W-w));
	}
	for(int i:rv)upd(i,-1);
	return vl;
}
void conquer(int u,int f,int dep,int len,vector<pii>&ar){
	if(rmv[u]||dep>L||len>W)return;
	ar.push_back({dep,len});
	for(auto[v,w]:elist[u]){
		if(v==f||rmv[v])continue;
		conquer(v,u,dep+1,len+w,ar);
	}
}
void divide(int x) {
	if(rmv[x])return;
	int c=fctr(x);
	vector<pii>tot;tot.push_back({0,0});
	for(auto[v,w]:elist[c])
		if(!rmv[v]){
			vector<pii>sub;conquer(v,c,1,w,sub);
			ans-=calc(sub);
			tot.insert(tot.end(),sub.begin(),sub.end());
		}
	ans+=calc(tot);
	rmv[c]=1;
	for(auto[v,w]:elist[c])
		if(!rmv[v])divide(v);
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    gi(n);gi(L),gi(W);
	iter(i,2,n+1){
		int u=i,v,w;gi(v),gi(w);
		elist[u].push_back({v,w});
		elist[v].push_back({u,w});
	}
	divide(1);
	cout<<(ans-n)/2<<endl;
}