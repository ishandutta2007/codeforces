#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL MOD = 1e13;
const int MAGIC = 3500000;

LL add(LL x, LL y)
{
	return (x + y) % MOD;
}
LL mul(LL x, LL y)
{
	LL coef = (long double)(x) * y / MOD + 0.5;
	LL ret = x * y - coef * MOD;
	ret += ret < 0 ? MOD : 0;
	return ret;
}

struct mat
{
	LL dat[2][2];
	mat()
	{
		memset(dat, 0, sizeof(dat));
	}
}I, J;

mat operator*(const mat& A, const mat& B)
{
	mat ret;
	rep(i, 2) rep(j, 2) ret.dat[i][j] = add(mul(A.dat[i][0], B.dat[0][j]), mul(A.dat[i][1], B.dat[1][j]));
	return ret;
}
void init()
{
	I.dat[0][0] = I.dat[1][1] = 1;
	J.dat[1][0] = J.dat[0][1] = J.dat[1][1] = 1;
}
LL calc(LL pos)
{
	mat ans = I, cur = J;
	while(pos > 0) {
		if(pos & 1) ans = ans * cur;
		cur = cur * cur; 
		pos >>= 1;
	}
	return ans.dat[1][0];
}


LL pw[14], cyc[14];
LL X;

int main()
{
	init();
	scanf("%lld", &X);
	
	pw[0] = 1;
	rep1(i, 13) pw[i] = 10 * pw[i - 1];

	cyc[0] = 1; cyc[1] = 60; cyc[2] = 300; cyc[3] = 1500;
	for(int i = 4; i <= 13; i ++) cyc[i] = 10 * cyc[i - 1];
	
	vector<LL> occ, nocc;
	occ.push_back(0);
	
	rep1(i, 13) {
		int wt = cyc[i] / cyc[i - 1];
		nocc.clear();
		rep(j, occ.size()) rep(k, wt) if(calc(occ[j] + k * cyc[i - 1]) % pw[i] == X % pw[i]) nocc.push_back(occ[j] + k * cyc[i - 1]);
		occ = nocc;
	}
	
	sort(occ.begin(), occ.end());
	printf("%lld\n", occ.empty() ? -1 : occ[0]);
	return 0;
}