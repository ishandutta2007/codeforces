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

const int nax = 5005;

vector <int> a, b;
int n;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	n *= 2;
	for(int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		a.pb(c);
		b.pb(c);
	}
	sort(b.begin(), b.end());
	int sum1 = 0, sum2 = 0;
	for(int i = 0; n / 2 > i; ++i) {
		sum1 += b[i];
		sum2 += b[i + n / 2];
	}
	if(sum1 == sum2) {
		cout << "-1\n";
		return 0;
	}
	for(auto it: b) {
		cout << it << " ";
	}
	
	
		
	
    return 0;
}