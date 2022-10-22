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

const int nax = 1e5 + 5;

vector <int> a, b;
int n;
int prime[nax];
int ans[nax];
int fre = 1;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 2; n >= i; ++i) {
		if(!prime[i]) {
			ans[i] = fre++;
			for(int j = 2 * i; n >= j; j += i) {
				ans[j] = fre - 1;
				prime[j] = 1;
			}
		}
	}
	//cout << fre - 1 << endl;
	for(int i = 2; i <= n; ++i) {
		cout << ans[i] << " ";
	}
			
	
	
		
	
    return 0;
}