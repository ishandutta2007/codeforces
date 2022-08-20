#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
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

string ori = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
ld len[100001];

void gen() {
    len[0] = ori.length();
    FOR(i,1,100001) {
        len[i] = 2*len[i-1]+a.length()+b.length()+c.length();
        if (len[i] > 2e18) len[i] = 2e18;
    }
}

void solve(int n, ll k) {
    if (k > len[n]) {
        cout << ".";
        return;
    }
    if (n == 0) {
        cout << ori[k-1];
        return;
    }
    if (k <= a.length()) {
        cout << a[k-1];
        return;
    }
    if (k <= a.length()+len[n-1]) solve(n-1,k-a.length());
    else if (k <= a.length()+len[n-1]+b.length()) {
        cout << b[k-1-a.length()-len[n-1]];
        return;
    } else if (k <= a.length()+len[n-1]+b.length()+len[n-1]) solve(n-1,k-a.length()-len[n-1]-b.length());
    else {
        cout << c[k-1-a.length()-len[n-1]-b.length()-len[n-1]];
        return;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	gen();
	int q; cin >> q;
	F0R(i,q) {
	    ll n,k; cin >> n >> k;
	    solve(n,k);
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!