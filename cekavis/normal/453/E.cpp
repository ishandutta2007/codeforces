#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<set>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005, M = N*18;
int cnt, n, q, root[N], s[N], m[N], r[N], lson[M], rson[M];
ll ans, sm[M], sr[M];
struct seg{
	int l, r, col;
	inline bool operator <(const seg &rhs)const{ return l<rhs.l||(l==rhs.l&&r<rhs.r);}
};
set<seg> a;
void modify(int l, int r, int &t, int pre, int a, int b, int c){
	t=++cnt;
	lson[t]=lson[pre], rson[t]=rson[pre], sm[t]=sm[pre]+b, sr[t]=sr[pre]+c;
	if(l==r) return;
	int mid=(l+r)/2;
	if(a<=mid) modify(l, mid, lson[t], lson[pre], a, b, c);
	else modify(mid+1, r, rson[t], rson[pre], a, b, c);
}
void query(int l, int r, int t, int pre, int x){
	if(l==r) return (void)(ans+=sm[t]-sm[pre]);
	int mid=(l+r)/2;
	if(x<=mid) ans+=(ll)x*(sr[rson[t]]-sr[rson[pre]]), query(l, mid, lson[t], lson[pre], x);
	else ans+=sm[lson[t]]-sm[lson[pre]], query(mid+1, r, rson[t], rson[pre], x);
}
inline void solve(int L, int R, int col){
	if(col<0) for(int i=L; i<=R; ++i) ans+=min((ll)m[i], s[i]-(ll)col*r[i]);
	else query(0, 100000, root[R], root[L-1], col);
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i){
		read(s[i]), read(m[i]), read(r[i]);
		if(!r[i] || !m[i]) root[i]=root[i-1];
		else modify(0, 100000, root[i], root[i-1], (m[i]-1)/r[i]+1, m[i], r[i]);
	}
	a.insert((seg){0, n+1, -1});
	read(q);
	for(int i=1, t, l, r; i<=q; ++i){
		ans=0;
		read(t), read(l), read(r);
		auto it=a.lower_bound((seg){l, n+2, 0});
		if((--it)->l<l) a.insert((seg){it->l, l-1, it->col});
		if(it->r>=r){
			solve(l, r, ~it->col?t-it->col:-t);
			if(it->r>r) a.insert((seg){r+1, it->r, it->col});
			a.erase(it);
			goto nxt;
		}
		solve(l, it->r, ~it->col?t-it->col:-t), a.erase(it++);
		while(it->r<=r) solve(it->l, it->r, ~it->col?t-it->col:-t), a.erase(it++);
		if(it->l<=r) solve(it->l, r, ~it->col?t-it->col:-t), a.insert((seg){r+1, it->r, it->col}), a.erase(it++);
		nxt:;
		a.insert((seg){l, r, t});
		print(ans), print('\n');
	}
	return flush(), 0;
}