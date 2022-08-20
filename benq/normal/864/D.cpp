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

int n, co[200001], num[200000], lst[200001], skip[200001];
queue<int> todo;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    cin >> num[i];
	    co[num[i]] ++;
	    lst[num[i]] = i;
	}
	FOR(i,1,n+1) if (co[i] == 0) todo.push(i);
	
	cout << todo.size() << "\n";
	F0R(i,n) {
	    bool s = 1, ns = 1;
	    if (skip[num[i]]) s = 0;
	    if (skip[num[i]] == 0 && i == lst[num[i]]) ns = 0;
	    if (todo.size() && todo.front() < num[i]) {
	        if (ns) {
	            num[i] = todo.front(); todo.pop();
	        } else {
	            skip[num[i]] = 1;
	            continue;
	        }
	    } else {
	        if (s) {
	            skip[num[i]] = 1;
	            continue;
	        } else {
	            num[i] = todo.front(); todo.pop();
	        }
	    }
	}
	F0R(i,n) cout << num[i] << " ";
}

// read!
// ll vs. int!