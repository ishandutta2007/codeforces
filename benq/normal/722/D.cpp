#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	set<int> used;
	int n; cin >> n;
	F0R(i,n) {
	    int z; cin >> z;
	    used.insert(z);
	}
	while(1) {
	    int x = -1;
	    for (int j = *prev(used.end()); j > 0; j /= 2) if (used.find(j) == used.end()) {
	        x = j;
	        break;
	    }
	    if (x == -1) break;
	    used.erase(prev(used.end()));
	    used.insert(x);
	}
	for (int i: used) cout << i << " ";
}