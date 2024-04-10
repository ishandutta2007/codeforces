#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<set>

using namespace std;
#define ll long long
#define Rep(i,x,y) for(int i=(x);i<(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig = false, c = read(); !isdigit(c); c = read()) {
		if (c == '-') iosig = true;
		if (c == -1) return;
	}
	for (x = 0; isdigit(c); c = read())
		x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (iosig) x = -x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
const int N = 200005, P = 998244353;
int n, q, addv[N<<2], mul[N<<2], s[N<<2];
set<pair<int,int> > se[N];
#define moo(x) if(x >= P) x -= P;
inline void push_down(int l, int r, int t) {
    int k = t << 1;
    if (mul[t] ^ 1) {
        addv[k] = (ll)addv[k] * mul[t] % P,
            addv[k + 1] = (ll)addv[k + 1] * mul[t] % P,
            mul[k] = (ll)mul[k] * mul[t] % P,
            mul[k + 1] = (ll)mul[k + 1] * mul[t] % P,
            s[k] = (ll)s[k] * mul[t] % P,
            s[k + 1] = (ll)s[k + 1] * mul[t] % P,
            mul[t] = 1;
    }
    if (addv[t]) {
        int m = l + r >> 1;
        addv[k] += addv[t];
        moo(addv[k]);
        addv[k + 1] += addv[t];
        moo(addv[k + 1]);
        s[k] = (s[k] + (ll)(m - l + 1)*addv[t]) % P,
            s[k + 1] = (s[k + 1] + (ll)(r - m)*addv[t]) % P,
            addv[t] = 0;
    }
}
inline void update(int t) {
    s[t] = s[t << 1] + s[t << 1 | 1];
    moo(s[t]);
}
void build(int l, int r, int t, int a[]) {
    addv[t] = 0;
    mul[t] = 1;
    if (!(l ^ r)) {
        s[t] = a[l];
        return;
    }
    int m = l + r >> 1, k = t << 1;
    build(l, m, k, a),
        build(m + 1, r, k + 1, a),
        update(t);
}
void change_add(int l, int r, int t, int x, int L, int R) {
    if (L <= l&&r <= R) {
        addv[t] += x;
        moo(addv[t]);
        s[t] = (s[t] + (ll)(r - l + 1)*x) % P;
    }
    else {
        push_down(l, r, t);
        int k = t << 1, m = l + r >> 1;
        if (L <= m) change_add(l, m, k, x, L, R);
        if (R > m) change_add(m + 1, r, k + 1, x, L, R);
        update(t);
    }
}
void change_mul(int l, int r, int t, int x, int L, int R) {
    if (L <= l&&r <= R) {
        addv[t] = (ll)addv[t] * x%P,
            mul[t] = (ll)mul[t] * x%P,
            s[t] = (ll)s[t] * x%P;
    }
    else {
        push_down(l, r, t);
        int k = t << 1, m = l + r >> 1;
        if (L <= m) change_mul(l, m, k, x, L, R);
        if (R > m) change_mul(m + 1, r, k + 1, x, L, R);
        update(t);
    }
}
int query(int l, int r, int t, int L, int R) {
    if (L <= l&&r <= R) return s[t]; else {
        int m = l + r >> 1, k = t << 1, ans = 0;
        push_down(l, r, t);
        if (L <= m) ans += query(l, m, k, L, R);
        if (R > m) ans += query(m + 1, r, k + 1, L, R);
        if (ans >= P) return ans - P; else return ans;
    }
}
int main() {
	read(n), read(q);
	rep(i, 1, n<<2) mul[i]=1;
	rep(i, 1, q){
		static int opt, l, r, x;
		read(opt), read(l), read(r);
		if(opt==1){
			read(x);
			auto &s=se[x];
			auto it=s.lower_bound(make_pair(l, l));
			if(it!=s.begin() && (--it)->second<l) ++it;
			if(it==s.end() || it->first>r){
				change_add(1, n, 1, 1, l, r), s.insert(make_pair(l, r));
				continue;
			}
			if(l<it->first){
				int tmpl=it->first, tmpr=it->second;
				change_add(1, n, 1, 1, l, tmpl-1);
				s.erase(it++);
				s.insert(make_pair(l, tmpr)), --it;
				l=tmpl;
			}
			change_mul(1, n, 1, 2, l, min(r, it->second)), l=it->second+1;
			int L=it->first;
			s.erase(it++);
			while(it!=s.end() && it->first<=r){
				change_add(1, n, 1, 1, l, it->first-1);
				change_mul(1, n, 1, 2, it->first, min(r, it->second)), l=it->second+1;
				s.erase(it++);
			}
			if(l<=r) change_add(1, n, 1, 1, l, r), l=r+1;
			s.insert(make_pair(L, l-1));
		}
		else print(query(1, n, 1, l, r)), print('\n');
	}
	return flush(), 0;
}