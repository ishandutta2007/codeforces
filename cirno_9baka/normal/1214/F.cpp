#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=262144;
const int M=998244353;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int n,m,i,s,x,fs,p[N],q[N],kp,kq,w[N];
long long ans;
struct str{
	int f,a,x;
}a[N],b[N];
bool cmp(str a,str b)
{
	return a.a<b.a;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	gi(m),gi(n);
	for(i=1;i<=n;++i)
	{
		gi(a[i].a);
		a[i].x=i;
		a[i].f=1;
	}
	for(i=n+1;i<=n*2;++i)
	{
		gi(a[i].a);
		a[i].x=i-n;
		a[i].f=-1;
	}
	sort(a+1,a+1+n*2,cmp);
	a[n*2+1].a=m;
	b[0].f=a[1].a;
	for(i=1;i<=n*2;++i)
	{
		b[i].a=b[i-1].a+a[i].f;
		b[i].f=a[i+1].a-a[i].a;
	}
	sort(b,b+1+n*2,cmp);
	s=m/2;
	for(i=0;i<=n*2;++i)
		if(s>=b[i].f)
			s-=b[i].f;
		else
		{
			x=b[i].a;
			break;
		}
	for(i=0;i<=n*2;++i)
		ans+=1ll*abs(b[i].a-x)*b[i].f;
	print(ans);
	putc('\n');
	bool flag=false;
	if(x>0)
	{
		flag=true;
		for(i=1;i<=n*2;++i)
			a[i].f=-a[i].f;
	}
	x=abs(x);
	kp=x;
	for(i=1;i<=n*2;++i)
		if(a[i].f==1)
			p[++kp]=a[i].x;
		else
			q[++kq]=a[i].x;
	for(i=x+1;i<=kq;++i)
		if(flag)
			w[q[i]]=p[i];
		else
			w[p[i]]=q[i];
	for(i=kq+1;i<=kp;++i)
		if(flag)
			w[q[i-kq]]=p[i];
		else
			w[p[i]]=q[i-kq];
	for(i=1;i<=n;++i)
	{
		print(w[i]);
		putc(' ');
	}
}