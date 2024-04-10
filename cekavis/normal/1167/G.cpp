#include<bits/stdc++.h>

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

const double Pi = acos(-1);
const int N = 200005, M = 7008;
int n, d, m, a[N<<1];
bitset<M> l, r;
int main() {
	read(n), read(d);
	for(int i=1, x=0; i<=n; ++i) read(x), a[i*2-1]=x, a[i*2]=x+1;
	read(m);
	int x=1, y=1, p=0, last=0;
	while(m--){
		read(p), l<<=p-last, r>>=p-last, last=p;
		for(; x<=n<<1 && a[x]<=p; x++) if(p-a[x]<M) l[p-a[x]]=1;
		for(; y<=n<<1 && a[y]-p<M; y++) if(p<=a[y]) r[a[y]-p]=1;
		if(x>2 && a[x-1]==p && a[x-2]==p) printf("%.15lf\n", Pi);
		else if(l[0]) printf("%.15lf\n", Pi/2);
		else printf("%.15lf\n", max(atan(1./min(l._Find_first(), r._Find_first())), 2*atan(1./(l&r)._Find_first())));
	}
	return 0;
}