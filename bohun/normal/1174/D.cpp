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
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 1e6 + 5;

int t[nax];
int n, x;
vector <int> ans;
vector <int> Real;
bool bad[nax];


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> x;
	for(int i = 1; (1 << n) > i; ++i) {
		if(!bad[i] && i != x) {
			ans.pb(i);
			bad[(i ^ x)] = 1;
		}
	}
	
	int last = 0;
	cout << ss(ans) << endl;
	for(auto it: ans) {
		Real.pb((it ^ last));
		last = it;
		cout << Real.back() << " ";
	}
	
	
	
	
			
	
	
		
	
    return 0;
}