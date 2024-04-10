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

vi pri;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k; cin >> n >> k;
	FOR(i,2,n+1) {
	    while (n % i == 0) {
	        pri.pb(i);
	        n /= i;
	    }
	}
	if (pri.size()<k) cout << -1;
	else {
	    F0R(i,k-1) cout << pri[i] << " ";
	    int tem = 1;
	    FOR(i,k-1,pri.size()) tem *= pri[i];
	    cout << tem;
	}
}