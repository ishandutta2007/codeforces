#include<bits/stdc++.h>
using namespace std;
const int N=505,E=200005;
int n,m,cnt[N],x[N],dp[805][4005],i,j;
int c[4005][4005],s[4005][4005];
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
int cost(int l,int r)
{
	return s[r][r]-s[r][l-1]-s[l-1][r]+s[l-1][l-1];
}
void dfs(int t,int l,int r,int ll,int rr)
{
	if(l>r)
		return;
	int mid=l+r>>1;
	int i;
	dp[t][mid]=1<<30;
	int mxx=0;
	for(i=ll;i<=rr&&i<=mid;++i)
		if(dp[t][mid]>cost(i,mid)+dp[t-1][i-1])
		{
			dp[t][mid]=cost(i,mid)+dp[t-1][i-1];
			mxx=i;
		}
	dfs(t,l,mid-1,ll,mxx);
	dfs(t,mid+1,r,mxx,rr);
}
int main()
{
	gi(n),gi(m);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			gi(c[i][j]);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+c[i][j];
	for(i=1;i<=n;++i)
		dp[1][i]=cost(1,i);
	for(i=2;i<=m;++i)
		dfs(i,1,n,1,n);
	cout<<dp[m][n]/2;
}