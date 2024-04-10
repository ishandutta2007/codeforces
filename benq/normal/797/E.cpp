#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pair<pii,pii>> query;
int a[100001], ans[100001],n,q;
pii rec[100001];

int get(int k, int p) {
    if (rec[p].f == k) return rec[p].s;
    if (p+a[p]+k > n) {
        rec[p] = {k,1};
        return 1;
    } else {
        rec[p] = {k,1+get(k,p+a[p]+k)};
        return rec[p].s;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	cin >> q;
	F0R(i,q) {
	    int p,k; cin >> p >> k;
	    query.pb(mp(mp(k,p),mp(i,0)));
	}
	sort(query.begin(),query.end());
	F0R(i,query.size()) ans[query[i].s.f] = get(query[i].f.f,query[i].f.s);
	F0R(i,q) cout << ans[i] << "\n";
}