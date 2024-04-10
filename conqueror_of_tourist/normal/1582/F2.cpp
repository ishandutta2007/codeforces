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

//#define int long long

typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
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

vector<vector<bool>> table(5001, vector<bool>(8192, false));
vector<vi> upd(5001);

void setv(int a, int b){
    if (!table[a][b]){
        table[a][b] = true;
        if (a){
            setv(a - 1, b);
        }
        upd[a].pb(b);
    }
}

void roll(int a){
    while (!upd[a].empty()){
        setv(a - 1, upd[a].back() ^ a);
        upd[a].pop_back();
    }
}

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	
	vi a(n);
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	}
	
	for(int i = 0; i <= 5000; i++){
	    setv(i, 0);
	}
	
	for(int i = n - 1; i >= 0; i--){
	    if (a[i] > 0) roll(a[i]);
	}
	
	vi out;
	for(int i = 0; i < 8192; i++){
	    if (table[0][i]){
	        out.pb(i);
	    }
	}
	
	cout << sz(out) << '\n';
	for (auto v: out){
	    cout << v << ' ';
	}
}