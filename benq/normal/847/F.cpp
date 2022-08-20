#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

int n,k,m,a, win[101];
vector<pii> num;

void process(vector<pii> num1) {
    memset(win,0,sizeof win);
    vector<pair<pii,int>> z;
    FOR(i,1,n+1) z.pb({num1[i],i});
    sort(z.begin(),z.end()); reverse(z.begin(),z.end());
    F0R(i,k) if (z[i].f.f > 0) win[z[i].s] = 1;
}

int test(int x) {
    vector<pii> num1 = num;
    if (m > a) {
        num1[x].f += m-a;
        num1[x].s = -m;
    }
    process(num1);
    if (!win[x]) return 3;
    if (num[x].f == 0) return 2;
    
    int bef = 0, ne = 0; 
    vi need;
    FOR(i,1,n+1) {
        if (num[i] > num[x]) bef ++;
        else if (i != x) need.pb(num[x].f-num[i].f+1);
    }
    sort(need.begin(),need.end());
    
    if (bef >= k) return 2;
    if (need.size() < k-bef) return 1;
    F0R(i,k-bef) ne += need[i];
    if (ne <= m-a) return 2;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> m >> a; num.resize(n+1);
	FOR(i,1,a+1) {
	    int x; cin >> x;
	    num[x].f ++;
	    num[x].s = -i;
	}
	FOR(i,1,n+1) cout << test(i) << " ";
}

// read!
// ll vs. int!