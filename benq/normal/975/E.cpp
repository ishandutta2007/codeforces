#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int n,q;
ld ori = 1;
vector<cd> p;
cd sum, cur;
pi z = {-1,-1};

cd get(int v) {
	if (z == mp(-1,-1)) return p[v];
	cd rotFactor = cd(0,-1)/(sum-p[z.f]);
	rotFactor /= abs(rotFactor);
	return (p[v]-p[z.f])*rotFactor+cur;
}

void genCen(vector<cd> p) {
	ld sum2 = 0;
	cd tmp = p[0];
	F0R(i,n) p[i] -= tmp;
	F0R(i,n) {
		int j = (i+1)%n;
		sum += (p[i]+p[j])*(p[i].real()*p[j].imag()-p[j].real()*p[i].imag());
		sum2 += (p[i].real()*p[j].imag()-p[j].real()*p[i].imag());
	}
	sum /= (3*sum2);
	sum += tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	F0R(i,n) {
		int x,y; cin >> x >> y;
		p.pb(cd(x,y));
	}
	genCen(p);
	cout << fixed << setprecision(10);
	F0R(i,q) {
		int t; cin >> t;
		if (t == 1) {
			int a,b; cin >> a >> b; a--, b--;
			if (z.f == -1) {
				if (a == 0) {
					z = {1,b};
					cur = p[1];
				} else {
					z = {0,b};
					cur = p[0];
				}
			} else {
				if (z.f == a) {
					cd t = get(z.s);
					cur = t;
					swap(z.f,z.s);
				} 
				z.s = b;
			}
		} else {
			int v; cin >> v; v--;
			cout << get(v).real() << " " << get(v).imag();
			cout << "\n";
		}
	}
}