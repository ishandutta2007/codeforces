#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
int n,a,b;
ll ans = 10000000000000000;
vi el, pri, pri2;
bool test[1000000];

void fac(int h) {
	F0R(j,pri.size()) {
		while (h % pri[j] == 0) h /= pri[j], pri2.pb(pri[j]);
		if (pri[j]*pri[j] > h) break;
	}
	if (h > 1) pri2.pb(h);
}

void genprime() {
	pri.pb(2);
	FOR(i,3,100000) F0R(j,pri.size()) {
		if (i % pri[j] == 0) break;
		if (pri[j]*pri[j] > i) {
			pri.pb(i); 
			break;
		}
	}
	fac(el[0]), fac(el[0]+1), fac(el[0]-1), fac(el[n-1]), fac(el[n-1]+1), fac(el[n-1]-1);
	sort(pri2.begin(), pri2.end() );
	pri2.erase( unique(pri2.begin(), pri2.end() ), pri2.end() );
}

ll t(int k) {
	ll val = 0;
	int lo = n, hi, c1 = 0, c2 = 0;
	memset(test, 0, sizeof(bool) * 1000000);
	F0R(i,n) {
		int x = el[i] % k;
		if (x == 1 || x == (k-1)) c1 ++, test[i] = 1;
		else if (x != 0) {
			lo = i;
			break;
		}
	}
	
	if (lo == n) {
		val = (ll)c1*b;
		ll maxsofar = 0, cur = 0, res = 0;
		F0R(i,n) {
			cur += a;
			if (test[i]) cur -= b;
			maxsofar = max(cur,maxsofar);
			res = min(res,cur-maxsofar);
		}
		return val + res;
	} else {
		for (int i = n-1; i >= 0; --i) {
			int x = el[i] % k;
			if (x == 1 || x == (k-1)) c2++, test[i] = 1;
			else if (x != 0) {
				hi = i;
				break;
			}
		}
		val = (ll)(hi-lo+1)*a+(ll)(c1+c2)*b;
		ll z1 = 0, minz1 = 0, z2 = 0, minz2 = 0;
		while (lo > 0) {
			lo --, z1 += a;
			if (test[lo]) z1 -= b;
			minz1 = min(minz1,z1);
		}
		while (hi < n-1) {
			hi ++, z2 += a;
			if (test[hi]) z2 -= b;
			minz2 = min(minz2,z2);
		}
		return (val + minz1 + minz2);
	}
}

int main() {
	cin >> n >> a >> b;
	el.resize(n);
	F0R(i,n) scanf("%d",&el[i]);
	genprime();
	F0R(i,pri2.size()) ans = min(ans,t(pri2[i]));
	cout << ans;
}