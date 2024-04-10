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

string a,b,ans;
int oc[10];

void greed() {
    sort(a.rbegin(),a.rend());
    cout << a;
}

void solve() {
    for (char c: a) oc[c-'0'] ++;
    
    string cur = "";
    F0R(i,sz(b)) {
        for (int j = int(b[i]-'0')-1; j >= 0; --j) if (oc[j]) {
            string z = cur+char('0'+j); oc[j] --;
            F0Rd(k,10) F0R(a,oc[k]) z += char('0'+k);
            ans = max(ans,z);
            oc[j] ++;
        }
        if (oc[b[i]-'0']) {
            cur += b[i];
            oc[b[i]-'0'] --;
            if (sz(cur) == sz(b) && cur <= b) ans = max(ans,cur);
        } else break;
    }
    
    cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> a >> b;
	if (sz(a) < sz(b)) greed();
	else solve();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!