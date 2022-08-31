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

int nex = 0;
vi paren, cur;
string s;
vector<pii> pairs;
ll rec[700][700][3][3];
bool done[700][700][3][3];

void init() {
	cin >> s; paren.resize(s.length());
	F0R(i,s.length()) {
		if (s[i] == '(') cur.pb(i);
		else {
			paren[cur[cur.size()-1]] = paren[i] = nex++;
			pairs.pb(mp(cur[cur.size()-1],i));
			cur.erase(cur.end()-1);
		}
	}
}

ll dp(int left, int right, int l, int r) {
	if (done[left][right][l][r]) return rec[left][right][l][r];
	if (paren[left] == paren[right]) {
		if (l == r) return 0;
		if (l > 0 && r > 0) return 0;
	}
	
	done[left][right][l][r] = 1;
	if (left+1 == right) rec[left][right][l][r] = 1;
	else if (paren[left] == paren[right]) {
		F0R(i,3) F0R(j,3) if ((i != l || i == 0) && (j != r || j == 0)) 
			rec[left][right][l][r] = (rec[left][right][l][r]+dp(left+1,right-1,i,j)) % MOD;
	} else {
		int up = pairs[paren[left]].s;
		F0R(i,3) F0R(j,3) if (i != j || i == 0) 
			rec[left][right][l][r] = (rec[left][right][l][r]+dp(left,up,l,i)*dp(up+1,right,j,r)) % MOD;
	}
	// cout << left << " " << right << " " << l << " " << r << " " << rec[left][right][l][r] << "\n";
	return rec[left][right][l][r];
}

int main() {
	/*F0R(i,s.length()) cout << paren[i] << " ";
	cout << "\n";*/
	ios_base::sync_with_stdio(0);cin.tie(0);
	init();
	ll ans = 0;
	F0R(i,3) F0R(j,3) ans = (ans+dp(0,s.length()-1,i,j)) % MOD;
	cout << ans;
}