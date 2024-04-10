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

const int N = 300005;
int n, ans, bl, br, gl, gr, rl, rr, a[N];
char col[N];
int main() {
	read(n);
	for(int i=1; i<=n; ++i){
		read(a[i]);
		while(isspace(col[i]=read()));
		if(col[i]=='B') bl=(bl?bl:a[i]), br=a[i];
		if(col[i]=='R') rl=(rl?rl:a[i]), rr=a[i];
		if(col[i]=='G') gl=(gl?gl:a[i]), gr=a[i];
	}
	if(!gl) return printf("%d\n", br-bl+rr-rl), 0;
	if(bl && bl<gl) ans+=gl-bl;
	if(rl && rl<gl) ans+=gl-rl;
	if(br && br>gr) ans+=br-gr;
	if(rr && rr>gr) ans+=rr-gr;
	int x=0;
	for(int i=1; i<=n; ++i) if(col[i]=='G'){ x=i; break;}
	while(1){
		int y=x+1;
		while(y<=n && col[y]!='G') ++y;
		if(y>n) break;
		int lastb=a[x], lastr=a[x], mxb=0, mxr=0;
		for(int i=x+1; i<y; ++i){
			if(col[i]=='B') mxb=max(mxb, a[i]-lastb), lastb=a[i];
			else mxr=max(mxr, a[i]-lastr), lastr=a[i];
		}
		mxb=max(mxb, a[y]-lastb), mxr=max(mxr, a[y]-lastr);
		ans+=min(2*(a[y]-a[x]), 3*(a[y]-a[x])-mxb-mxr);
		x=y;
	}
	return printf("%d", ans), 0;
}