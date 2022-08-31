/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, co[1000001], cou[1000001];
ll po2[200001], ans = 0;

void solve(int x) {
    cou[x] += x;
    int num = 0;
    for (int i = x; i <= 1000000; i += x) {
        num += co[i];
        if (i != x) cou[i] -= cou[x];
    }
    if (num == 0) return;
    while (cou[x] < 0) cou[x] += MOD;
    
    ll tmp = po2[num-1]*num % MOD; 
    tmp = tmp*cou[x] % MOD; // this is not correct
    ans = (ans+tmp) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	po2[0] = 1;
	FOR(i,1,200001) po2[i] = po2[i-1]*2 % MOD;
	cin >> n;
	F0R(i,n) {
	    int a; cin >> a;
	    co[a] ++;
	}
	
	FOR(i,2,1000001) solve(i);
	cout << ans;
}