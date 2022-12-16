#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct item {
	ll val;
	int ind;
	bool operator<(const item& o) const {
		return val < o.val;
	}
};

ll n, m, k, s;
vector<ll> dollar, pound, dday, pday;
vector<item> ditems, pitems;

void readIt() {
	cin >> n >> m >> k >> s;
	ll minn = 1e7; ll v, mday = 0;
	dollar.push_back(1e16);
	pound.push_back(1e16);
	pday.push_back(-1); dday.push_back(-1);
	for(int i=1;i<=n;++i) {
		cin >> v;
		if(minn > v) {
			minn = v;
			mday = i;
		}
		dollar.push_back(minn);
		dday.push_back(mday);
	}
	minn = 1e7; mday=0;
	for(int i=1;i<=n;++i) {
		cin >> v;
		if(minn > v) {
			mday = i;
			minn = v;
		}
		pound.push_back(minn);
		pday.push_back(mday);
	}
	int type;
	for(int i=0;i<m;++i) {
		cin >> type >> v;
		if(type == 1) ditems.push_back({v, i+1});
		if(type == 2) pitems.push_back({v, i+1});
	}
	sort(ditems.begin(), ditems.end());
	sort(pitems.begin(), pitems.end());
}

bool isPossible(int days, bool verbose) {
	ll d = dollar[days];
	ll p = pound[days];
	//cerr; if(verbose) //cerr << "-- " << d << " " << p << endl;
	int dit = 0, pit = 0;
	ll total = 0;
	for(int i=0;i<k;++i) {
		if(dit == ditems.size()) {
			if(verbose) cout << pitems[pit].ind << " " << pday[days] << nl;
			total += pitems[pit++].val*p;
			continue;
		}
		else if(pit == pitems.size()) {
			if(verbose) cout << ditems[dit].ind << " " << dday[days] << nl;
			total += ditems[dit++].val*d;
			continue;
		}
		
		//cerr; if(verbose) //cerr << "!! " << ditems[dit].val*d << " " << pitems[pit].val*p << " .. " << dit << " " << pit << endl;
		if(ditems[dit].val*d < pitems[pit].val*p) {
			if(verbose) cout << ditems[dit].ind << " " << dday[days] << nl;
			total += ditems[dit++].val*d;
		} else {
			if(verbose) cout << pitems[pit].ind << " " << pday[days] << nl;
			total += pitems[pit++].val*p;
		}
	}
	if(total <= s) return true;
	return false;
}

int getDay() {
	int l = 0, r = n;
	while(l < r) {
		int m = (l+r+1)/2;
		if(isPossible(m, false)) {
			r = m-1;
		} else {
			l = m;
		}
	}
	if(l == n) return -1;
	return l+1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	readIt();
	int day = getDay();

	if(day == -1) {cout << -1 << endl;}
	else {
		cout << day << nl;
		isPossible(day, true);
	}

	return 0;
}