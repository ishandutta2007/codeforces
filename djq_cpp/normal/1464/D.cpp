#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int pw3[400005];
int n, p[1000005];
bool vis[1000005];

int D0(int cts, int cnt, int cnt1, int cnt2, int cnt3, int cnt4)
{
	if(cnt4 == 0) return MOD;
	cts --; cnt1 --;
	if(cnt2 > cnt1) cts += (cnt2 - cnt1) / 3;
	cts += cnt + cts - n / 3;
	return cts;
}
int D1(int cts, int cnt, int cnt1, int cnt2, int cnt3, int cnt4)
{
	if(cnt2 * 2 + cnt1 < 4) return MOD;
	if(cnt2 > 0) cnt2 --; else cnt1 -= 2;
	if(cnt2 > 0) cnt2 --; else cnt1 -= 2;
	if(cnt2 > cnt1) cts += (cnt2 - cnt1) / 3;
	cts += cnt + cts - n / 3 - 1;
	return cts;
}

int D2(int cts, int cnt, int cnt1, int cnt2, int cnt3, int cnt4)
{
	if(cnt3 == 0) return MOD;
	cnt1 --;
	if(cnt2 > cnt1) cts += (cnt2 - cnt1) / 3;
	cts += cnt + cts - n / 3;
	return cts;
}

void solve()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &p[i]);
	
	int cnt = 0, cts = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	rep1(i, n) vis[i] = false;
	rep1(i, n) if(!vis[i]) {
		int j = i, len = 0;
		do {
			vis[j] = true; j = p[j]; len ++;
		} while(j != i);
		cnt ++;
		cts += (len - 1) / 3;
		cnt1 += len % 3 == 1;
		cnt2 += len % 3 == 2;
		cnt3 += len >= 3;
		cnt4 += len % 3 == 1 && len >= 4;
	}
	
	int ta = 0;
	if(n % 3 == 0) {
		ta = pw3[n / 3];
		if(cnt2 > cnt1) cts += (cnt2 - cnt1) / 3;
		cts += cnt + cts - n / 3;
	} else if(n % 3 == 2) {
		ta = pw3[n / 3] * 2 % MOD;
		if(cnt2 > 0) cnt2 --;
		else cnt1 -= 2;
		if(cnt2 > cnt1) cts += (cnt2 - cnt1) / 3;
		cts += cnt + cts - n / 3 - 1;
	} else if(n % 3 == 1) {
		ta = pw3[(n - 4) / 3] * 4LL % MOD;
		int A0 = D0(cts, cnt, cnt1, cnt2, cnt3, cnt4);
		int A1 = D1(cts, cnt, cnt1, cnt2, cnt3, cnt4);
		int A2 = D2(cts, cnt, cnt1, cnt2, cnt3, cnt4);
		cts = min(min(A0, A1), A2);
	}
	
	printf("%d %d\n", ta, cts);
}
int main()
{
	pw3[0] = 1;
	rep1(i, 400000) pw3[i] = pw3[i - 1] * 3LL % MOD;
	
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}