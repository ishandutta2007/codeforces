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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

ll n,d,x;
int ans[100000], a[100000], b[100000], pos[100001], mx;
vi B;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> d >> x; mx = n;
	F0R(i,n) a[i] = i+1;
	F0R(i,n) swap(a[i],a[getNextX()%(i+1)]);
	F0R(i,n) if (i<d) b[i] = 1;
	else b[i] = 0;
	F0R(i,n) swap(b[i],b[getNextX()%(i+1)]);
	F0R(i,n) if (b[i]) B.pb(i);
	
	F0R(i,n) pos[a[i]] = i;
}

int getleft() {
    int tmp = 0;
    F0R(i,n) if (ans[i] == 0) tmp++;
    return tmp;
}

void process() {
    for (int j: B) if (pos[mx]+j < n) ans[pos[mx]+j] = max(ans[pos[mx]+j],mx);
    mx --;
}

void brute() {
    vi tmp;
    if (mx > 0) {
        F0R(i,n) if (ans[i] == 0) tmp.pb(i);
        for (int i: tmp) for (int j: B) if (i >= j) ans[i] = max(ans[i],a[i-j]);
    }
    F0R(i,n) cout << ans[i] << "\n";
}

int main() {
    init();
	while (getleft()*d > 1e8 && mx > 0) process();
	brute();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!