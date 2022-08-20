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

vector<pii> A,B;
vector<pair<double,pii>> vert;
int n, m;

ll signarea(pii v1, pii v2, pii x) {
	x.f -= v1.f, x.s -= v1.s;
	v2.f -= v1.f, v2.s -= v1.s;
	return (ll)v2.f*x.s-(ll)v2.s*x.f;
}

bool isin(pii x) {
	F0R(i,n) if (signarea(A[i],A[(i+1)%n],x)>=0) return 0;
	return 1;
}

bool ok (pii a) {
	auto it = lb(vert.begin(),vert.end(),mp(atan2(a.s-B[0].s,a.f-B[0].f),a));
	auto p2 = *it, p1 = *prev(it);
	/*cout << p1.f << " " << p1.s << "\n";
	cout << " HI " << p2.f << " " << p2.s << "\n";
	cout << a.f << " " << a.s << "\n\n";*/
	if (signarea(p1.s,p2.s,a) <= 0) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; A.resize(n);
	F0R(i,n) cin >> A[i].f >> A[i].s;
	cin >> m; B.resize(m);
	F0R(i,m) cin >> B[i].f >> B[i].s;
	if (!isin(B[0])) {
		cout << "NO";
		return 0;
	}
	vert.resize(n);
	F0R(i,n) vert[i] = mp(atan2(A[i].s-B[0].s,A[i].f-B[0].f),A[i]);
	sort(vert.begin(),vert.end());
	vert.insert(vert.begin(),vert[n-1]);
	vert[0].f -= 2*PI;
	vert.pb(vert[1]); vert[vert.size()-1].f += 2*PI;
	FOR(i,1,m) if (!ok(B[i])) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
}