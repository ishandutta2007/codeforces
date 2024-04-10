#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<bitset>

using namespace std;
#define ll long long
#define ull unsigned ll
#define rep(i,x,y) for(int i=(x);i<=(y);++i)

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
const int N = 200005;
int cnt, n, m, d[N], x[N], y[N], id[N], *e[N];
ull A, B, C, ans;
bitset<N> f[900];
inline ull calc(int l, int r){ return (ull)(l+r)*(r-l+1)/2;}
int main() {
	read(n), read(m);
	read(A), read(B), read(C);
	rep(i, 1, m){
		read(x[i]), read(y[i]);
		if(x[i]>y[i]) swap(x[i], y[i]);
		++d[x[i]], ++d[y[i]];
		ans-=B*calc(x[i]+1, y[i]-1)+(A*x[i]+C*y[i])*(y[i]-x[i]-1) + A*calc(0, x[i]-1)+(B*x[i]+C*y[i])*x[i] + C*calc(y[i]+1, n-1)+(A*x[i]+B*y[i])*(n-y[i]-1);//solve 1
	}
	for(int i=0; i<n; ++i) e[i]=new int[d[i]+1], d[i]=0;
	rep(i, 1, m) e[x[i]][d[x[i]]++]=y[i], e[y[i]][d[y[i]]++]=x[i];
	int lim=sqrt(m);
	for(int i=0; i<n; ++i){
		ans+=i*(C*calc(1, i-1)+A*calc(1, n-i-2)+B*i*(n-i-1)), sort(e[i], e[i]+d[i]);//solve 0
		if(d[i]>=lim){
			id[i]=++cnt;
			for(int j=0; j<d[i]; ++j) f[cnt][e[i][j]]=1;
		}
	}
	for(int i=0; i<n; ++i){
		ull s0=0, s1=0, t0=0, t1=0;
		for(int j=0; j<d[i]; ++j) if(e[i][j]<i){
			ans+=A*s1+B*s0*e[i][j]+C*s0*i;//solve 2
			++s0, s1+=e[i][j];
		}
		else{
			ans+=A*s1+C*s0*e[i][j]+B*s0*i + A*t0*i+B*t1+C*t0*e[i][j];//solve 2
			++t0, t1+=e[i][j];
		}

		if(d[i]<lim)
			for(int j=0; j<d[i] && e[i][j]<i; ++j){
				int v=e[i][j];
				if(d[v]<lim){
					int k=0;
					for(int t=j+1; t<d[i] && e[i][t]<i; ++t){
						while(k<d[v] && e[v][k]<e[i][t]) ++k;
						if(e[v][k]==e[i][t]) ans-=A*v+B*e[i][t]+C*i;//solve 3
					}
				}
				else for(int t=j+1; t<d[i] && e[i][t]<i; ++t)
					if(f[id[v]][e[i][t]]) ans-=A*v+B*e[i][t]+C*i;//solve 3
			}
		else rep(j, 1, m) if(y[j]<i && f[id[i]][x[j]] && f[id[i]][y[j]]) ans-=A*x[j]+B*y[j]+C*i;//solve 3
	}
	return printf("%llu", ans), 0;
}