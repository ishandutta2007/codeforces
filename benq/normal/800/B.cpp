#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n; 
double d = 1e12;
vector<pair<ll,ll>> vert;

double dist(pair<ll,ll> a, pair<ll,ll> b) {
	a.f -= b.f, a.s -= b.s;
	return sqrt(a.f*a.f+a.s*a.s);
}

double area(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c) {
	b.f -= a.f, b.s -= a.s;
	c.f -= a.f, c.s -= a.s;
	return (abs(b.f*c.s-b.s*c.f)/2.0);
}

void test(pair<ll,ll> a, pair<ll,ll> b,pair<ll,ll> c) {
	d = min(d,area(a,b,c)/dist(a,c));
}

int main() {
	cin >> n;
	F0R(i,n) {
		pair<ll,ll> x; cin >> x.f >> x.s;
		vert.pb(x);
	}
	F0R(i,n) test(vert[i],vert[(i+1)%n],vert[(i+2)%n]);
	cout << fixed << setprecision(9) << d;
}