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
const int MX = 300001;

int n,k;
bool in[MX];
int co[MX];
ll mx[MX];

void reduce(int x) {
    FOR(i,1,x+1) co[i] = 0;
    pii mx = {0,0};
    FOR(i,1,x+1) if (in[i]) {
        for (int j = 2*i; j <= x; j += i) if (in[j]) {
            co[i] ++;
            co[j] ++;
        }
    }
    FOR(i,1,x+1) if (co[i] <= k) mx = max(mx,{co[i],i});
    k -= mx.f;
    in[mx.s] = 0;
}

void solve(int x) {
    k = mx[x]-k;
    FOR(i,1,x+1) in[i] = 1;
    while (k > 0) reduce(x);
    int t = 0; FOR(i,1,MX) if (in[i]) t++;
    cout << "Yes\n" << t << "\n";
    FOR(i,1,MX) if (in[i]) cout << i << " ";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	FOR(i,1,MX) for (int j = 2*i; j < MX; j += i) mx[j] ++;
	FOR(i,2,MX) mx[i] += mx[i-1];
	FOR(i,1,n+1) if (mx[i] >= k) solve(i);
	cout << "No";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!