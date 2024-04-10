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

int n,k;
ll ans[100000], a[100001];
int oc[500000];
int a1[100001], a2[100001], a3[100001];
map<ll,int> key;
vector<vi> query;
ll cur = 0;

int lo = 0, hi = -1, block = 300;

bool cmp(vi a, vi b) {
    if (a[0]/block != b[0]/block) return a[0] < b[0];
    return a[1] < b[1];
}

void process(vi A) {
    while (lo > A[0]) {
        lo--;
        cur += oc[a3[lo]];
        oc[a2[lo]] ++;
    }
    while (hi < A[1]) {
        hi ++;
        cur += oc[a1[hi]];
        oc[a2[hi]] ++;
    }
    while (lo < A[0]) {
        oc[a2[lo]] --;
        cur -= oc[a3[lo]];
        lo++;
    }
    while (hi > A[1]) {
        oc[a2[hi]] --;
        cur -= oc[a1[hi]];
        hi--;
    }
    ans[A[2]] = cur;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	FOR(i,1,n+1) {
	    int x; cin >> x;
	    if (x == 1) a[i] = 1;
	    else a[i] = -1;
	}
	FOR(i,1,n+1){
	    int x; cin >> x;
	    a[i] *= x;
	    a[i] += a[i-1];
	}
	
	F0R(i,n+1) key[a[i]-k] = key[a[i]] = key[a[i]+k] = 0;
	int z = 0;
	for (auto& a: key) a.s = ++z;
	F0R(i,n+1) {
	    a1[i] = key[a[i]-k];
	    a2[i] = key[a[i]];
	    a3[i] = key[a[i]+k];
	}
	
	int q; cin >> q;
	F0R(i,q) {
	    int l,r; cin >> l >> r;
	    query.pb({l-1,r,i});
	}
	sort(query.begin(),query.end(),cmp);
	for (auto a: query) process(a);
	F0R(i,q) cout << ans[i] << "\n";
}

// read!
// ll vs. int!