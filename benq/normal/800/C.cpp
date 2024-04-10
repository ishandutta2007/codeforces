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
#define int long long

const int MOD = 1000000007;
double PI = 4*atan(1);

map<int,vi> co;
map<int,pii> dp; // number, next
vi div1;
set<int> divi;
bool ok[200000];
int n,m; 

void EE(int a, int b, int& x, int& y) {
    if(a%b == 0) {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}

int inverse(int a, int m) {
    int x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

int get(int a, int b, int mod) {
	if (b == 0) return 0;
	int gcd = __gcd(a,mod); a /= gcd, b /= gcd, mod /= gcd;
	int cur = __gcd(b,mod); b /= cur, mod /= cur;
	return cur*((inverse(a,mod)*b) % mod);
}

main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	
	F0R(i,m) ok[i] = 1;
	F0R(i,n) {
		int x; cin >> x;
		ok[x] = 0;
	}
	
	F0R(i,m) divi.insert(__gcd(i,m));
	for (int i: divi) div1.pb(i);
	reverse(div1.begin(),div1.end());
	F0R(i,m) if (ok[i]) co[__gcd(i,m)].pb(i);
	
	for (int i: div1) {
		for (int j: div1) 
			if (j % i == 0 && j > i) 
				if (dp[j].f > dp[i].f) {
					dp[i].f = dp[j].f;
					dp[i].s = j;
				}
		dp[i].f += co[i].size();
	}
	int cur = 1;
	vi ans, ans1;
	while (1) {
		for (int i: co[cur]) ans.pb(i);
		cur = dp[cur].s;
		if (cur == 0) break;
	}
	ans1.pb(ans[0]);
	F0R(i,ans.size()-1) ans1.pb(get(ans[i],ans[i+1],m));
	
	cout << ans1.size() << "\n";
	for (int i: ans1) cout << i << " ";
}