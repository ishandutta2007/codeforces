#include <bits/stdc++.h>
#define LL unsigned long long
#define uint unsigned
using namespace std;
template <typename T> void read(T &x){
	static char ch; x = 0,ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
}
inline void write(int x){if (x<0)x=-x,putchar('-');if (x > 9) write(x/10); putchar(x%10+'0'); }
const int N = 31,Q = 1001; const uint mod = 19260817;
int n,q;
struct Bs{
	LL B[16];
	Bs(){ memset(B,0,128); }
	inline void init(){ memset(B,0,128); }
	inline void ins(int p){ B[p>>6] |= 1ull<<(p&63); }
	inline void rd(){init(); int t,p; read(t); while (t--) read(p),ins(p); }
	inline void Xor(Bs &T){
		B[0]^=T.B[0],B[1]^=T.B[1],B[2]^=T.B[2],B[3]^=T.B[3],
		B[4]^=T.B[4],B[5]^=T.B[5],B[6]^=T.B[6],B[7]^=T.B[7],
		B[8]^=T.B[8],B[9]^=T.B[9],B[10]^=T.B[10],B[11]^=T.B[11],
		B[12]^=T.B[12],B[13]^=T.B[13],B[14]^=T.B[14],B[15]^=T.B[15];
	}
	inline LL gethash(){
		//2^64 % 19260817 == 1729901
		LL res = 0;
		for (register int i = 0; i < 16; ++i) res = (res * 1729901ull + B[i]) % mod;
		return res % mod;
	}
	inline void copy(Bs &T){ memcpy(B,T.B,128); }
	inline bool Equal(Bs &T){
		for (register int i = 0; i < 16; ++i) if (B[i] ^ T.B[i]) return 0; return 1;
	}
};
//typedef bitset<1024> Bs;
const int V = (1<<20)|1;
Bs qv,tmp;
struct Hash{
	Bs v1[V]; int v2[V],Ne[V],_;
	int He[19260817];
	Hash(){ _ = 0; }
	inline void Ins(Bs &T,int val){
		int hv = T.gethash(),x = He[hv];
		while (x){
			if (v1[x].Equal(T)){ v2[x] = min(v2[x],val); return; }
			x = Ne[x];
		}
		++_; Ne[_] = He[hv],He[hv] = _,v1[_] = T,v2[_] = val;
	}
	inline int ask(){
		int hv = qv.gethash(),x = He[hv];
		while (x){
			if (v1[x].Equal(qv)) return v2[x];
			x = Ne[x];
		}
		return 1000;
	}
}H1,H2;
Bs a[N];
Bs res1[1<<15],res2[1<<20]; int siz[1<<20],ans;
int main(){
//	cerr << 2.0 * sizeof(H1)  /1024 /1024<<'\n';
	register int i,j; int v;
	read(i),read(n),read(q);
	for (i = 1; i <= n; ++i) a[i].rd();
	n = max(n,30);
	random_shuffle(a+1,a+n+1);
	for (i = 1; i <= 10; ++i) res1[1<<(i-1)] = a[i];
	for (i = 11; i <= 30; ++i) res2[1<<(i-11)] = a[i];
	for (i = 0; i < 1<<20; ++i){
		siz[i] = siz[i>>1] + (i&1),v = i&-i;
		if (i != v){
			if (i<(1<<10)) res1[i].copy(res1[v]),res1[i].Xor(res1[v^i]);
			res2[i].copy(res2[v]),res2[i].Xor(res2[v^i]);
		}
		if (i<(1<<10)) H1.Ins(res1[i],siz[i]);
		H2.Ins(res2[i],siz[i]);
	}
	if (H1._ > H2._){
		for (i = 1; i <= q; ++i){
			qv.init(),qv.rd(),ans = 1000,tmp.copy(qv);
			for (j = 1; j <= H2._; ++j){
				qv.copy(tmp),qv.Xor(H2.v1[j]);
				if (H2.v2[j] < ans) ans = min(ans,H2.v2[j] + H1.ask());
			}
			if (ans > 30) ans = -1;
			write(ans),putchar('\n');
		}
		return 0;
	}
	for (i = 1; i <= q; ++i){
		qv.init(),qv.rd(),ans = 1000,tmp.copy(qv);
		for (j = 1; j <= H1._; ++j){
			qv.copy(tmp),qv.Xor(H1.v1[j]);
			if (H1.v2[j] < ans) ans = min(ans,H1.v2[j] + H2.ask());
		}
		if (ans > 30) ans = -1;
		write(ans),putchar('\n');
	}	
	return 0;
}