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

int n, oc[26];
string S[100000];
vector<string> cur, cur1;

void bad(string s) {
    memset(oc,0,sizeof oc);
    for (char c: s) {
        if (oc[c-'a']) {
            cout << "NO";
            exit(0);
        }
        oc[c-'a'] ++;
    }
}

string comb(string a, string b) {
    F0R(i,a.length()) F0R(j,b.length()) if (a[i] == b[j]) {
        string A;
        FOR(k,-26,27) {
            bool ok0 = (0 <= i+k && i+k < (int)a.length());
            bool ok1 = (0 <= j+k && j+k < (int)b.length());
            if (ok0 && ok1) {
                if (a[i+k] != b[j+k]) {
                    cout << "NO";
                    exit(0);
                }
                A += a[i+k];
            } else if (ok0) A += a[i+k];
            else if (ok1) A += b[j+k];
        }
        bad(A);
        return A;
    }
    cur1.pb(b);
    return a;
}

void process(string t) {
    cur1.clear();
    for (auto& a: cur) t = comb(t,a);
    cur1.pb(t);
    cur = cur1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    cin >> S[i];
	    bad(S[i]);
	    process(S[i]);
	}
	sort(cur.begin(),cur.end());
	for (auto a: cur) cout << a;
}

// read!
// ll vs. int!