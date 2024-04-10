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

int n, mx = 0;
string st[100000];
vector<pii> oc[2000001], remoc[2000001];
multiset<pii> cur;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	
	F0R(i,n) {
	    cin >> st[i];
	    int k; cin >> k;
	    F0R(j,k) {
	        int x; cin >> x;
	        oc[x-1].pb({i,x-1});
	        remoc[x-1+st[i].length()].pb({i,x-1});
	        mx = max(mx,x-1+(int)st[i].length()-1);
	    }
	}
	
	string ans = "";
	F0R(i,mx+1) {
	    for (auto a: oc[i]) cur.insert(a);
	    for (auto a: remoc[i]) cur.erase(a);
	    if (cur.size()) {
	        pii z = *cur.begin();
	        ans += st[z.f][i-z.s];
	    } else ans += 'a';
	}
	cout << ans;
}