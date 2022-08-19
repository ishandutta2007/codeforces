#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define rep1(i, n) for(int i = 1; i <= (n); i ++)

typedef long long LL;
typedef pair<int, int> PII;
int MOD;

int n, lsq;
int cur[305];
int ans[305];

int input_d(int l, int r)
{
	int ret = 0;
	cout << "? " << l << ' ' << r << endl;
	cin >> ret;
	return ret;
}

void output_d()
{
	cout << "! ";
	rep1(i, n) cout << ans[i];
	cout << endl;
}

int gxor(int l, int r)
{
	int ret;
	do {
		ret = input_d(l, r);
		ret = input_d(l, r);
	} while(ret == lsq);
	rep1(i, n) if(i < l || i > r) cur[i] ^= 1;
	return ret;
}

void query_ev(int x)
{
	int ret = gxor(x, x);
	if(n - ret > lsq) ans[x] = cur[x]; 
	else ans[x] = cur[x] ^ 1;
	lsq = ret;
}

void query_od(int x)
{
	int ret = gxor(x, x + 1);
	if(n - ret == lsq) ans[x] = cur[x] ^ cur[x + 1] ^ 1;
	else ans[x] = cur[x] ^ cur[x + 1];
	lsq = ret;
}

int p[305];

void solve_ev()
{
	rep1(i, n) query_ev(p[i]);
}

void solve_od()
{
	int tot = lsq;
	rep1(i, n) if(p[i] != n) query_od(p[i]);
	for(int i = n - 1; i >= 1; i --) ans[i] ^= ans[i + 1];
	rep1(i, n) if(ans[i]) tot --;
	if(tot != 0) rep1(i, n) ans[i] ^= 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> lsq;
	rep1(i, n) p[i] = i;
	random_shuffle(p + 1, p + n + 1);
	if(n & 1) solve_od();
	else solve_ev();
	output_d();
	return 0;
}