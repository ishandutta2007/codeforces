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

int main() {
    int x;
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	int odd = 0;
	bool ans = true;
	if(n % 2 == 0){
	    ans = false;
	}
	else{
	    for(int i = 0; i < n; i++){
	        cin >> x;
	        if(i == 0 && x % 2 != 1){
	            ans = false;
	        }
	        if(i == n-1 && x % 2 != 1){
	            ans = false;
	        }
	    }
	}
	if(ans == true){
	    cout << "Yes";
	}
	else cout << "No";
}

// read!
// ll vs. int!