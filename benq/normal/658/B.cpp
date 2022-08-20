#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int n,k,q, t[150000];
	set<pii> cur;
	cin >> n >> k >> q;
	F0R(i,n) cin >> t[i];
	F0R(i,q) {
		int type, id;
		scanf("%d%d",&type,&id);
		if (type == 1) {
			cur.insert(mp(t[id-1],id));
			if (cur.size() > k) cur.erase(cur.begin());
		} else {
			if (cur.find(mp(t[id-1],id)) != cur.end()) {
				cout << "YES" << endl;
			} else cout << "NO" << endl;
		}
		// cout << id << endl;
	}
	return 0;
}