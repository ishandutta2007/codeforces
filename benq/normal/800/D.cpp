#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int MOD = 1000000007;

pair<ll,pair<ll,ll>> atleast[1000000]; // number, sum of squares, sum
ll co[1000000], ans[1000000], po2[1000000];

void calc(int num) {
	int a[6], a1[6], tnum = num;
	F0Rd(i,6) {
		a[i] = (tnum % 10);
		tnum /= 10;
	}
	FOR(i,1,1<<6) {
		int co = 0;
		F0R(j,6) a1[j] = a[j];
		F0R(j,6) if (i & (1<<j)) {co++; a1[j] ++;}
		bool flag = 0;
		F0R(j,6) if (a1[j] == 10) flag = 1;
		if (flag) continue;
		
		int num1 = 0;
		F0R(j,6) num1 = 10*num1+a1[j];
		if (co % 2 == 1) {
			atleast[num].f += atleast[num1].f;
			atleast[num].s.f = atleast[num].s.f+atleast[num1].s.f;
			atleast[num].s.s = atleast[num1].s.s+atleast[num].s.s;
		} else {
			atleast[num].f -= atleast[num1].f;
			atleast[num].s.f -= atleast[num1].s.f;
			atleast[num].s.s -= atleast[num1].s.s;
		}
	}
	atleast[num].s.f %= MOD;
	atleast[num].s.s %= MOD;
	while (atleast[num].s.f<0) atleast[num].s.f += MOD;
	while (atleast[num].s.s<0) atleast[num].s.s += MOD;
	if (atleast[num].f == 0) return;
	else if (atleast[num].f == 1) ans[num] = atleast[num].s.f;
	else {
		ans[num] = po2[atleast[num].f-2];
		ans[num] *= ((atleast[num].s.s*atleast[num].s.s+atleast[num].s.f) % MOD);
		ans[num] %= MOD;
	}
}

ll get(int num) {
	int a[6], a1[6], tnum = num;
	F0Rd(i,6) {
		a[i] = (tnum%10);
		tnum /= 10;
	}
	ll c = ans[num];
	FOR(i,1,1<<6) {
		int co = 0;
		F0R(j,6) a1[j] = a[j];
		F0R(j,6) if (i & (1<<j)) co++, a1[j] ++;
		bool flag = 0;
		F0R(j,6) if (a1[j] == 10) flag = 1;
		if (flag) continue;
		
		int num1 = 0;
		F0R(i,6) num1 = 10*num1+a1[i];
		if (co % 2 == 1) c -= ans[num1];
		else c += ans[num1];
	}
	c %= MOD;
	while (c<0) c += MOD;
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	po2[0] = 1; FOR(i,1,1000000) po2[i] = (2*po2[i-1]) % MOD;
	
	F0R(i,n) {
		ll x; cin >> x;
		atleast[x].f ++;
		atleast[x].s.f = (atleast[x].s.f+x*x) % MOD;
		atleast[x].s.s = (atleast[x].s.s+x) % MOD;
	}
	ll cur = 0;
	F0Rd(i,1000000) {
		calc(i);
		cur ^= (i*get(i));
	}
	cout << cur;
}