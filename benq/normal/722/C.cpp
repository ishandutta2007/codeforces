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

ll cum[100001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	FOR(i,1,n+1) {
	    int x; cin >> x;
	    cum[i] = cum[i-1]+x;
	}
	multiset<ll> sums;
	sums.insert(cum[n]);
	set<int> des;
	des.insert(0); des.insert(n+1);
	F0R(i,n) {
	    int x; cin >> x;
	    des.insert(x);
	    auto a = des.find(x);
	    auto b = *prev(a), c = *next(a);
	    // cout << (cum[c-1]-cum[b]) << "\n";
	    // if (sums.find(cum[c-1]-cum[b]) == sums.end()) cout << "hi" << "\n";
	    sums.erase(sums.find(cum[c-1]-cum[b]));
	    sums.insert(cum[x-1]-cum[b]);
	    sums.insert(cum[c-1]-cum[x]);
	    cout << *sums.rbegin() << "\n";
	}
}