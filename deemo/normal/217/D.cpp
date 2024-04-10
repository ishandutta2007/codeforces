//May your love never end
//And if you need a friend, there's a seat here alongside me..

#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXM = 120;
const int MOD = 1e9 + 7;

int ans;
int m, cnt[MAXM], mx;
bitset<MAXM> zz;

bitset<MAXM> rot(bitset<MAXM> x, int y, bool t = 0){
	bitset<MAXM> temp = x;
	temp <<= y;
	temp &= zz;
	x >>= m-y;
	if (t)
		temp[y] = 1;
	return temp | x;
}

void gen(int ind = 1, int cc = 0, int sm = 1, bitset<MAXM>	us = 0){
	ans += sm;
	while (ans >= MOD)
		ans -= MOD;
	if (cc == 6)	return;

	for (; ind <= mx; ind++)
		if (cnt[ind] && !us[m - ind] && !us[ind])
			if ((us & rot(us, ind)) == 0)	gen(ind + 1, cc + 1, (ll)sm * cnt[ind] % MOD, us|rot(us, ind, 1));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	{
		int n;	cin >> n >> m >> n;
		while (n--){
			int x;	cin >> x, x %= m;
			x = min(x, m - x);
			cnt[x]++;
			mx = max(mx, x);
		}
		for (int i = 0; i < m; i++)
			zz[i] = 1;
	}
	gen();
	cout << ans << endl;
	return 0;
}