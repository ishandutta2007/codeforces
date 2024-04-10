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

bool eq(cd a, cd b) { return abs(a-b) < EPS; }
cd normalize(cd z) { return z / abs(z); }

// reflects z over the line through a and b
cd reflect(cd z, cd a, cd b) { return conj((z-a)/(b-a)) * (b-a) + a; }

// projects z onto the line through a and b
cd proj(cd z, cd a, cd b) { return (z + reflect(z, a, b))/(ld)2; }

// check collinearity
bool collinear(cd a, cd b, cd c) { return abs(imag((b-a)/(c-a))) < EPS; }

// intersection of the line through a,b with the line through c,d
cd intersect(cd a, cd b, cd c, cd d) {
    cd num = (conj(a)*b - a*conj(b))*(c-d) - (a-b)*(conj(c)*d - c*conj(d));
    cd den = (conj(a) - conj(b))*(c-d) - (a-b)*(conj(c) - conj(d));
    return num / den;
}
cd circumcenter(cd a, cd b, cd c) {
    b -= a, c -= a;
    return (b*norm(c) - c*norm(b))/(b*conj(c) - c*conj(b)) + a;
}
//calculate angle abc
ld angle(cd a, cd b, cd c) {
	cd ab = normalize(b - a);
	cd bc = normalize(b - c);
	cd rot = ab / bc;
	ld ang = acos(real(rot));
	return min(abs(ang), 2*PI - abs(ang));
}

ld solve(cd a, cd b, cd c) {
	ld A = angle(b,a,c);
	ld B = angle(a,b,c);
	ld C = angle(a,c,b);
	//dbg(A _ B _ C _ A + B + C);
	ld aa = A + (PI/3);
	ld bb = B + (PI/3);
	ld cc = C + (PI/3);

	ld Ac = sin(bb) * sin(cc) * sin(A);
	ld Bc = sin(aa) * sin(cc) * sin(B);
	ld Cc = sin(bb) * sin(aa) * sin(C);
	
	cd fermat = Ac * a + Bc *b + Cc * c;
	fermat /= (Ac + Bc + Cc);
	
	//dbg(angle(a,fermat,b));
	//dbg(angle(a,fermat,c));
	//dbg(angle(c,fermat,b));

	vld dist;
	dist.pb(abs(a-b));
	dist.pb(abs(a-c));
	dist.pb(abs(c-b));
	sort(all(dist));
	ld ans = dist[0] + dist[1];
	return min(ans, abs(fermat - a) + abs(fermat - b) + abs(fermat - c));
}
const int epoch = 1000;
const int N = epoch * 100;

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cout << fixed << setprecision(12);
	vector<cd> friends(3);
	M00(i, 3) {
		ld x, y; cin >> x >> y;
		friends[i] = complex(x,y);
	}
	cd me = (friends[0] + friends[1] + friends[2]) / ((ld) 3.0);
	M00(iter, N) {
		ld mu = 0.4 / (iter + 5);
		if(iter > N/2) mu /= 5;

		vld dists;
		dists.pb(solve(friends[0],friends[1],me));
		dists.pb(solve(friends[0],friends[2],me));
		dists.pb(solve(friends[2],friends[1],me));

		if(dists[0] <= min(dists[1], dists[2])) {
			me = (1.0 - mu) * me + mu * friends[2];
		}
		else if(dists[1] <= min(dists[0], dists[2])) {
			me = (1.0 - mu) * me + mu * friends[1];
		}
		else if(dists[2] <= min(dists[1], dists[0])) {
			me = (1.0 - mu) * me + mu * friends[0];
		}
		
		ld best = max(dists[0], max(dists[1], dists[2]));
		if(iter == N-1) {
			cout << best << endl;
		}
		if(iter % epoch == 0) {
			//cout << best << endl;
		}
	}

}