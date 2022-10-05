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
const int N = 210;
int n;

int arr[N][N];
int pref[N][N];
int inner[N][N];
int total[N];
int ptotal[N];


vi ans(N);


//# of messages between things in l to r
int within(int i, int j) {
	if(j < i) return 0;
	if(inner[i][j] == -1) {
		if(i == j)  {
			inner[i][j] = 0;
		} else {
			inner[i][j] = within(i, j-1);
			inner[i][j] += pref[j][j] - pref[j][i];
		}
	}
	return inner[i][j];
}
//sum_x of messages from x
int totaler(int l, int r) {
	return ptotal[r+1] - ptotal[l];
}
//cost, root
pi spliter[N][N];

pi split(int l, int r) {
	if(r < l) return mp(0, -1);

	if(spliter[l][r].f == -1) {
		int bcost = 1e15;
		int broot = -1;
		for(int x = l; x <= r; x++) {
			int cost = 0;
			cost += split(l, x-1).f;
			cost += split(x+1, r).f;
			cost += totaler(l, x-1) - 2*within(l, x-1);
			cost += totaler(x+1, r) - 2*within(x+1, r);
			if(cost <= bcost) {
				bcost = cost;
				broot = x;
			}
		}
		spliter[l][r] = mp(bcost, broot);
	}
	return spliter[l][r];
}
void solve(int l, int r, int p) {
	if(r < l) return;
	int root = split(l, r).s;
	ans[root] = p;
	solve(l, root-1, root);
	solve(root+1, r, root);
}

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	M00(i, N) M00(j, N) inner[i][j] = -1;
	M00(i, N) M00(j, N) spliter[i][j] = mp(-1,-1);
	cin >> n;
	M00(i, n) M00(j, n) cin >> arr[i][j];
	M00(i, n) M00(j, n) pref[i][j+1] = pref[i][j] + arr[i][j];
	M00(i, n) M00(j, n) {
		total[i] += arr[i][j];
	}
	M00(i, n) ptotal[i+1] = ptotal[i] + total[i];

	solve(0, n-1, -1);
	M00(i, n) cout << ans[i] + 1 << " ";
	cout << endl;
}