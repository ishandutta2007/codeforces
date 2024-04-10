/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
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

int n,a,b,ans=0;
vector<pii> ok;

int t(pii x, pii y) {
    return (x.f+y.f <= b && max(x.s,y.s) <= a);
}

int t2(pii x, pii y) {
    return (max(x.f,y.f) <= b && x.s+y.s <= a);
}

int test(int x, int y) {
    int area = ok[x].f*ok[x].s+ok[y].f*ok[y].s;
    if (t(ok[x],ok[y]) || t2(ok[x],ok[y])) return area;
    swap(ok[x].f,ok[x].s);
    if (t(ok[x],ok[y]) || t2(ok[x],ok[y])) return area;
    swap(ok[y].f,ok[y].s);
    if (t(ok[x],ok[y]) || t2(ok[x],ok[y])) return area;
    swap(ok[x].f,ok[x].s);
    if (t(ok[x],ok[y]) || t2(ok[x],ok[y])) return area;
    return 0;
}

int main() {
	cin >> n >> a >> b;
	F0R(i,n) {
	    int x,y; cin >> x >> y;
	    ok.pb({x,y});
	}
	F0R(i,n) FOR(j,i+1,n) ans = max(ans,test(i,j));
	cout << ans;
}