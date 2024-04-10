#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int mod = 1e9 + 7, nax = 100005;

int n, q;
pair <int, int> ans[nax];	
ll a;
deque <int> de;		
int maks = 0;	
int ile = 0;
int j = 1;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		int b;
		cin >> b;
		de.push_back(b);
		
		maks = max(maks, b);
	}
	
	while(de.front() != maks) {
		int a = de.front();
		de.pop_front();
		int b = de.front();
		de.pop_front();
		ans[j++] = mp(a, b);
		int A = min(a, b);
		int B = max(a , b);
		de.push_back(A);
		de.push_front(B);
		++ile;
	}
	
	while(q--) {
		cin >> a;
		if(a <= j - 1) {
			cout << ans[a].fi << " " << ans[a].se << endl;
			continue;
		}
		a -= j - 1;
		a %= (n - 1);
		cout << maks << " ";
		if(a == 0) {
			cout << de.back() << endl;
		}
		else {
			cout << de[a] << endl;
		}
	}
		
	
	
	
	
	
	
	
				
	
	
	return 0;
}