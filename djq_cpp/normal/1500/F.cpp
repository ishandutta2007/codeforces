//zabana, zibile
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

namespace IO
{
	const int BSIZ = 4096;
	char bufi[4105], bufo[4105];
	int posi = BSIZ, poso;
	void getC(char& ch)
	{
		if(posi == BSIZ) {
			memset(bufi, 0, sizeof(bufi));
			fread(bufi, 1, BSIZ, stdin); posi = 0;
		}
		ch = bufi[posi ++];
	}
	template<typename T>
	void getU(T& x)
	{
		char ch; x = 0;
		do getC(ch);
		while(ch < '0' || ch > '9');
		do {
			x = x * 10 + (ch - '0'); getC(ch);
		} while(ch >= '0' && ch <= '9');
	}
	void putC(char ch)
	{
		if(ch == EOF || poso == BSIZ) {
			fwrite(bufo, 1, poso, stdout); poso = 0;
		}
		if(ch != EOF) bufo[poso ++] = ch;
	}
	char buf[25];
	template<typename T>
	void putU(T x)
	{
		int len = 0;
		do {
			buf[len ++] = x % 10 + '0'; x /= 10;
		} while(x != 0);
		for(int i = len - 1; i >= 0; i --) putC(buf[i]);
	}
}
using namespace IO;

int n, coef[1000005];
LL C, w[1000005], rd[1000005];
int pre[1000005];
LL pv[1000005];

struct deq
{
	int fr, rr, id[2000010], c1;
	LL c0, l[2000010], r[2000010];
	LL rval(LL x)
	{
		return c0 + c1 * x;
	}
	LL ival(LL x)
	{
		return (x - c0) * c1;
	}
	void rev(LL w)
	{
		c0 = w - c0; c1 = -c1;
	}
	void init(LL cl = 0, LL cr = C, LL cid = 0)
	{
		fr = rr = 1000005;
		c0 = 0; c1 = 1;
		id[rr] = cid; l[rr] = cl; r[rr] = cr; rr ++;
	}
	
	bool popbad()
	{
		if(c1 == -1) {
			for(; rr > fr; rr --)
			if(rval(l[rr - 1]) >= 0) {
				if(rval(r[rr - 1]) < 0) r[rr - 1] = ival(0);
				return false;
			}
		} else {
			for(; fr < rr; fr ++)
			if(rval(r[fr]) >= 0) {
				if(rval(l[fr]) < 0) l[fr] = ival(0);
				return false;
			}
		}
		return true;
	}
	bool hv0()
	{
		if(c1 == -1) return rval(r[rr - 1]) == 0;
		else return rval(l[fr]) == 0;
	}
	void pushmx(LL x, int cid)
	{
		if(c1 == -1) {
			fr --; l[fr] = r[fr] = ival(x); id[fr] = cid;
		} else {
			l[rr] = r[rr] = ival(x); id[rr] = cid; rr ++;
		}
	}
}que;

int main()
{
	getU(n); getU(C);
	rep1(i, n - 2) getU(w[i]);
	
	que.init();
	rep1(i, n - 2) {
		bool o0 = que.hv0();
		que.rev(w[i]);
		if(que.popbad()) {
			putC('N'); putC('O'); putC('\n'); putC(EOF);
			return 0;
		}
		bool n0 = que.hv0();
		if(n0) {
			pre[i] = que.c1 == -1 ? que.id[que.rr - 1] : que.id[que.fr]; pv[i] = w[i];
			que.init(0, w[i], i);
		} else if(!o0) {
			pre[i] = que.id[que.fr]; pv[i] = w[i] - que.rval(que.l[que.fr]);
			que.pushmx(w[i], i);
		}
	}
	
	putC('Y'); putC('E'); putC('S'); putC('\n');
	rd[n - 2] = que.rval(que.l[que.fr]);
	for(int i = n - 2; i > que.id[que.fr]; i --) rd[i - 1] = w[i] - rd[i];
	for(int p = que.id[que.fr]; p != 0; p = pre[p]) {
		rd[p - 1] = pv[p];
		for(int j = p - 1; j > pre[p]; j --) rd[j - 1] = w[j] - rd[j];
	}
	
	coef[0] = 1;
	rep1(i, n - 2) if(w[i] == max(rd[i], rd[i - 1])) coef[i] = -coef[i - 1];
	else coef[i] = coef[i - 1];
	
	for(int i = n - 2; i >= 0; i --) rd[i] = rd[i] * coef[i] + rd[i + 1];
	LL mn = 0;
	rep(i, n) mn = min(mn, rd[i]);
	rep(i, n) rd[i] -= mn;
	
	rep(i, n) {
		putU(rd[i]); putC(i == n - 1 ? '\n' : ' ');
	}
	putC(EOF);
	return 0;
}