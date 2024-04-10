#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<bitset>

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

const int N = 200005, M = 105;
int n, F, cnt, ans, f[N], prime[N];
bool p[N];
bitset<N> a, g[M];
int main() {
	read(n), read(F);
	for(int i=2; i<=200000; ++i){
		if(!p[i]) prime[++cnt]=i, a[i]=1;
		for(int j=1; j<=cnt && i*prime[j]<=200000; ++j){
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=1; i<=cnt; ++i) for(int j=1; prime[i]*prime[j]<=200000; ++j)
		a[prime[i]*prime[j]]=1;
	a[F]=0;
	for(int i=0; i<200000; ++i){
		while(g[f[i]][i]) ++f[i];
		g[f[i]]|=a<<i;
	}
	while(n--){
		static int x, y, z;
		read(x), read(y), read(z);
		ans^=f[y-x-1]^f[z-y-1];
	}
	puts(ans?"Alice\nBob":"Bob\nAlice");
	return 0;
}