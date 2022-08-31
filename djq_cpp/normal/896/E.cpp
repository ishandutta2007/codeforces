#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int BSIZ = 1500;

char bufi[65545];
int curi = 65536;
char getcr()
{
	if(curi == 65536) {
		bufi[fread(bufi, 1, 65536, stdin)] = EOF;
		curi = 0;
	}
	return bufi[curi ++];
}
int getint()
{
	int ret = 0;
	char ch;
	do ch = getcr();
	while(ch < '0' || ch > '9');
	do {
		ret = ret * 10 + ch - '0';
		ch = getcr();
	} while(ch >= '0' && ch <= '9');
	return ret;
}

char bufo[65545];
int curo = 0;
void putcr(char x)
{
	if(curo == 65536 || x == EOF) {
		fwrite(bufo, 1, curo, stdout);
		curo = 0;
	}
	if(x != EOF) bufo[curo ++] = x;
}
char sta[15];
int scnt;
void putint(int x)
{
	scnt = 0;
	do {
		sta[scnt ++] = x % 10 + '0';
		x /= 10;
	} while(x > 0);
	for(int i = scnt - 1; i >= 0; i --) putcr(sta[i]);
}

namespace block
{
	int l, r;
	int par[500005], siz[500005];
	void init()
	{
		l = 0;
		r = 500000;
		memset(par, -1, sizeof(par));
		memset(siz, 0, sizeof(siz));
	}
	
	int root(int x)
	{
		return par[x] == -1 ? x : par[x] = root(par[x]);
	}
	
	void addpar(int u, int v)
	{
		v = root(v);
		par[u] = v;
		siz[v] += siz[u];
	}
	
	void dec(int x)
	{
		if(r - l >= 2 * x) {
			for(int i = l + 1; i <= l + x; i ++) addpar(i, i + x);
			l += x;
		} else if(r - l > x) {
			for(int i = l + x + 1; i <= r; i ++) addpar(i, i - x);
			r = l + x;
		}
	}
	
	int dec1(int v, int x)
	{
		v = root(v);
		if(v <= l + x) return v; 
		siz[v] --;
		v -= x;
		siz[v] ++;
		return v;
	}
	
	int query(int x)
	{
		if(x <= 0 || x > r - l) return 0;
		return siz[l + x];
	}
	
	int query1(int x)
	{
		return root(x) - l;
	}
}

int n, q, a[500005];
int qt[500005], ql[500005], qr[500005], qx[500005], qans[500005];

int main()
{
	n = getint();
	q = getint();
	rep(i, n) a[i] = getint();
	rep(i, q) {
		qt[i] = getint();
		ql[i] = getint() - 1;
		qr[i] = getint() - 1;
		qx[i] = getint();
	}
	for(int i = 0; i < n; i += BSIZ) {
		int j = i + BSIZ - 1;
		block::init();
		for(int k = i; k <= j; k ++) block::siz[a[k]] ++;
		rep(k, q) if(qt[k] == 1) {
			if(ql[k] <= i && qr[k] >= j) block::dec(qx[k]);
			else for(int p = max(i, ql[k]); p <= min(j, qr[k]); p ++) a[p] = block::dec1(a[p], qx[k]);
		} else {
			if(ql[k] <= i && qr[k] >= j) qans[k] += block::query(qx[k]);
			else for(int p = max(i, ql[k]); p <= min(j, qr[k]); p ++) qans[k] += block::query1(a[p]) == qx[k];
		}
	}
	rep(i, q) if(qt[i] == 2) {
		putint(qans[i]);
		putcr('\n');
	}
	putcr(EOF);
	return 0;
}