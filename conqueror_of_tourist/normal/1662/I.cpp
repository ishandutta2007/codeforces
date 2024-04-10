#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))

#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)

#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<

#define int long long

typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;

const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 1e9+7;

int POW(int b, int e) {
	int r = 1;
	while(e) {
		if(e % 2 == 1) {
			r *= b;
			r %= MOD;
		}
		e /= 2;
		b *= b;
		b %= MOD;
	}
	return r;
}
int gcd(int a, int b) {
	if(b > a) return gcd(b,a);
	if(b == 0) return a;
	return gcd(b, a % b);
}
int INV(int a) {
	return POW(a, MOD-2);
}
//Constants and Variables here


int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, m;
	cin >> n >> m;
	vi pep(n), dist(m);
	M00(i, n) cin >> pep[i];
	M00(i, m) cin >> dist[i];
	vector<bool> taken(n);
	M00(i, m) {
		if(dist[i] % 100 == 0 && dist[i]/100 < n) {
			taken[dist[i]/100] = true;
		}
	}
	vector<pi> events;
	M00(i, n) {
		if(!taken[i]) events.pb(mp(100*i, pep[i]));
	}
	M00(i, m) events.pb(mp(dist[i], -1));
	sort(all(events));

	//Events are (dist, pop or -1) for store
	int pref = 0, suff = 0;
	int last = -1e8;
	bool start = true;
	vector<pi> S;
	int ans = 0;
	for(auto p : events) {
		int d = p.f, pop = p.s;
		if(p.s < 0) {
			suff = 0;
			//do sweepline BS
			if(!start) {
				int delta = d - last;
				int span = (delta - 1)/2;
				int SS = S.size();
				if(SS != 0) {
					int r = 0;
					int accum = S[0].s;
					M00(l, SS) {
						if(r < l) { 
							r = l;
							accum = S[r].s;
						}
						while(r != SS-1 && S[r+1].f - S[l].f <= span) {
							r++;
							accum += S[r].s;
						}
						ans = max(ans, accum);
						accum -= S[l].s;
					}
				}
			}
			//end BS
			start = false;
			last = d;
			S.clear();
		} else {
			suff += pop;
			if(start) pref += pop;
			else S.pb(p);
		}
	}
	ans = max(ans, max(pref, suff));
	cout << ans << endl;
}