#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

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

const int N = 500005;
ll tot, ans;
int n, A, B, C, g[N], h[N];
struct fan{
	int a, b, c;
	inline bool operator <(const fan &rhs)const{ return a<rhs.a;}
} f[N];
int main() {
	read(n), read(A), read(B), read(C);
	for(int i=1; i<=n; ++i)
		read(f[i].a), read(f[i].b), read(f[i].c),
		g[f[i].b]=max(g[f[i].b], f[i].c),
		h[f[i].c]=max(h[f[i].c], f[i].b);
	for(int i=B; --i;) g[i]=max(g[i], g[i+1]);
	for(int i=C; --i;) h[i]=max(h[i], h[i+1]);
	for(int i=1; i<=B; ++i) tot+=g[i];
	sort(f+1, f+n+1);
	int j=n, mxz=0, mxy=0;
	for(int i=A; i; --i){
		while(j && f[j].a==i){
			while(f[j].b>mxy) tot+=C-max(g[++mxy], mxz);
			while(f[j].c>mxz) tot+=B-max(h[++mxz], mxy);
			--j;
		}
		ans+=(ll)B*C-tot;
	}
	return printf("%lld", ans), 0;
}