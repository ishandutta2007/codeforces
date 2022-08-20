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

ll n,k,pr[100000][20];
int csum[20], cind[20];
vector<pii> prim;

void gen() {
	for (int x = 2;;++x) {
		if (k % x == 0) {
			int co = 0;
			while (k % x == 0) {
				k /= x;
				co ++;
			}
			prim.pb({x,co});
		}
		if (x*x > k) break;
	}
	if (k != 1) prim.pb({k,1});
}

void fill(int i, int num) {
	F0R(j,prim.size()) while (num % prim[j].f == 0) {
		pr[i][j] ++;
		num /= prim[j].f;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	
	if (k == 1) {
		cout << n*(n+1)/2;
		return 0;
	}
	
	gen();
	
	
	F0R(i,n) {
		int num; cin >> num;
		fill(i,num);
	}
	
	F0R(i,prim.size()) cind[i] = -1;
	
	ll fin = 0;
	F0R(i,n) {
		int ans = 0;
		if (i != 0) 
			F0R(j,prim.size()) csum[j] -= pr[i-1][j];
			
		F0R(j,prim.size()) {
			while (cind[j] < n-1 && csum[j] < prim[j].s) {
				cind[j] ++;
				csum[j] += pr[cind[j]][j];
			}
			if (csum[j] < prim[j].s) ans = MOD;
			else ans = max(ans,cind[j]);
		}
		
		if (ans != MOD) fin += (n-ans);
	}
	
	cout << fin;
}