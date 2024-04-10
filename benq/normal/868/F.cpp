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
const ll INF = 1000000000000000000LL;

int n,k,a[100001], freq[100001];
ll ans[100001][21];
ll ccost = 0;
int cl = 1, cr = 0;

void slide(int l, int r) {
    while (cr < r) {
        cr++;
        ccost += freq[a[cr]];
        freq[a[cr]] ++;
    }
    while (cl > l) {
        cl --;
        ccost += freq[a[cl]];
        freq[a[cl]] ++;
    }
    while (cr > r) {
        freq[a[cr]] --;
        ccost -= freq[a[cr]];
        cr --;
    }
    while (cl < l) {
        freq[a[cl]] --;
        ccost -= freq[a[cl]];
        cl++;
    }
    if (ccost < 0) exit(100);
}

void fill(int lev, int l, int r, int optl, int optr) {
    if (l > r) return;
    optr = min(optr,r);
    optl = max(optl,0);
    int m = (l+r)/2;
    
    ans[m][lev] = INF;
    int bes = -1;
    FOR(i,optl,min(optr+1,m)) {
        slide(i+1,m);
        if (ccost+ans[i][lev-1] < ans[m][lev]) {
            ans[m][lev] = ccost+ans[i][lev-1];
            if (ans[m][lev] < 0) {
                cout << optl << " " << ccost << " " << i << " " << lev << " " << ans[i][lev-1] << " " << ans[m][lev];
                exit(101);
            }
            bes = i;
        }
    }
    fill(lev,l,m-1,optl,bes);
    fill(lev,m+1,r,bes,optr);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,100001) F0R(j,21) ans[i][j] = 0;
	FOR(i,1,n+1) cin >> a[i];
	FOR(i,1,n+1) {
	    slide(1,i);
	    ans[i][1] = ccost;
	}
	FOR(i,2,k+1) fill(i,1,n,1,n);
	if (ans[n][k] < 0) exit(103);
	cout << ans[n][k];
}

// read!
// ll vs. int!