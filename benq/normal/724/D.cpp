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

set<int> cur;
vi x[26];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int m; cin >> m;
	string s; cin >> s;
	F0R(i,s.length()) x[s[i]-'a'].pb(i);
	cur.insert(-1);
	cur.insert(s.length());
	F0R(i,26) {
	    for (int j: x[i]) cur.insert(j);
	    bool f = 1;
	    auto xz = cur.begin(), y = next(cur.begin());
	    while (y != cur.end()) {
	        if ((*y-*xz)>m) {
	            f = 0;
	            break;
	        }
	        xz = y;
	        y = next(y);
	    }
	    if (f == 1) {
	        for (int j: x[i]) cur.erase(j);
	        int ans = 0, l = 0;
	        auto y = next(cur.begin());
	        
	        F0R(j,cur.size()-1) {
	            int xz = *prev(y);
	            while ((*y-xz) > m) {
	                while (l<(x[i].size()-1) && x[i][l+1] <= (xz+m)) l++;
	                xz = x[i][l], ans++;
	            }
	            y = next(y);
	        }
	        F0R(i1,i) F0R(j,x[i1].size()) cout << char('a'+i1);
	        F0R(i1,ans) cout << char('a'+i);
	        return 0;
	    }
	}
}