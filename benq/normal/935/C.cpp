#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<double,double> pd;
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
const double PI = 4*atan(1);

double R;
pd p1, p2;

double dist(pd p1, pd p2) {
    return sqrt((p1.f-p2.f)*(p1.f-p2.f)+(p1.s-p2.s)*(p1.s-p2.s));
}

pd operator+(pd a, pd b) {
    return {a.f+b.f,a.s+b.s};
}

pd getop() {
    if (p1 == p2) return {p1.f+R,p1.s};
    pd tmp = {p1.f-p2.f,p1.s-p2.s};
    double t = R/dist({0,0},tmp);
    tmp.f *= t, tmp.s *= t;
    return tmp+p1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> p1.f >> p1.s >> p2.f >> p2.s;
    cout << fixed << setprecision(8);
    if (dist(p1,p2) > R) cout << p1.f << " " << p1.s << " " << R;
    else {
        pd x = getop();
        pd cen = {(x.f+p2.f)/2,(x.s+p2.s)/2};
        cout << cen.f << " " << cen.s << " " << dist(cen,p2);
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)