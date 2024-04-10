#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

vector<string> names;
map<string,int> code;
vector<pii> d;
vi des;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	names.resize(n);
	F0R(i,n) cin >> names[i];
	sort(names.begin(),names.end());
	F0R(i,n) code[names[i]] = i;
	F0R(i,m) {
		string a,b; cin >> a >> b;
		d.pb(mp(code[a],code[b]));
	}
	int ans = 0;
	F0R(i,1<<n) {
		int cur = 0;
		F0R(j,n) if (i & (1<<j)) cur++;
		if (cur <= ans) continue;
		bool flag = 0;
		for (pii x: d) if ((i & (1<<x.f)) != 0 && (i & (1<<x.s)) != 0) {
			flag = 1;
			break;
		}
		if (flag) continue;
		ans = cur;
		des.clear();
		F0R(j,n) if (i & (1<<j)) des.pb(j);
	}
	cout << ans << "\n";
	F0R(i,ans) cout << names[des[i]] << "\n";
}