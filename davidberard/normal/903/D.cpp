#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

int c1;

struct state {
	int h1, a1, h2, a2, level;
	int laststate;
	state() {}
	state(int a, int b, int c, int d, int e, int f)
		:h1(a), a1(b), h2(c), a2(d), level(e), laststate(f) {}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;
	cin >> N;
	vector<ull> a(N);
	for(int i=0;i<N;++i) {
		cin >> a[i];
	}
	ull prfx = 0;
	map<int,ull> removals;
	map<int,ull> rcount;
	ull nans = 0, pans = 0;
	for(int i;i<N;++i) {
		ull tp = ((ull) a[i])*i;
		if(tp > prfx)
			pans += tp-prfx;
		else
			nans += prfx-tp;
		if(removals.count(a[i]) != 0) {
			ull ot = ((ull)a[i])*rcount[a[i]];
			ull rmls = removals[a[i]];
			if(ot > rmls)
				nans += ot-rmls;
			else
				pans += rmls-ot;
		}
		prfx += a[i];
		if(rcount.count(a[i]-1) == 0)
			rcount[a[i]-1] = 0;
		if(rcount.count(a[i]+1) == 0)
			rcount[a[i]+1] = 0;
		if(rcount.count(a[i]) == 0)
			rcount[a[i]] = 0;
		if(removals.count(a[i]-1) == 0)
			removals[a[i]-1] = 0;
		if(removals.count(a[i]+1) == 0)
			removals[a[i]+1] = 0;
		if(removals.count(a[i]) == 0)
			removals[a[i]] = 0;
		removals[a[i]-1] += a[i];
		removals[a[i]+1] += a[i];
		removals[a[i]] += a[i];
		++ rcount[a[i]+1];
		++ rcount[a[i]-1];
		++ rcount[a[i]];

		if(pans > nans) {
			pans -= nans;
			nans = 0;
		} else {
			nans -= pans;
			pans = 0;
		}
	}

	if(pans > 0 || (pans == 0 && nans == 0))
		cout << pans << endl;
	else
		cout << "-" << nans << endl;

	return 0;
}