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
int ile;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		if(c % 2)
			ile++;
		a.pb(c);
	}
	if(ile == n || ile == 0) {
		;
	}
	else {
		sort(a.begin(), a.end());
	}
	for(auto it: a)
		cout << it << " ";
	
		
	
    return 0;
}