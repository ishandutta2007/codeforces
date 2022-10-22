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

string s;
int n, a, b;
int dp[nax];
int pref[3 * nax];
int maxi[3 * nax];
int suf[3 * nax];

void fun(int x) {
	string c = s.substr(1, x);
	reverse(c.begin(), c.end());
	c = c + '#' + c;
	c = '1' + c;
	pref[1] = 0;
	int N = ss(c) - 1, L = -1, R = -1;
	for(int i = 2; i <= N; ++i) {
		pref[i] = 0;
		if(i <= R) {
			pref[i] = min(pref[i - L + 1], R - i);
		}
		while(i + pref[i] <= N && c[i + pref[i]] == c[pref[i] + 1])
			pref[i]++;
		if(i + pref[i] - 1 > R) {
			L = i;
			R = i + pref[i] - 1;
		}
	}
	for(int i = x + 2; i <= N; ++i) {
		maxi[i - x - 1] = pref[i];
	}
	for(int i = x; 1 <= i; --i) {
		suf[i] = max(suf[i + 1], maxi[i]);
	}
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> a >> b;
	cin >> s;
	s = '2' + s;
	for(int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + a;
		fun(i);
		for(int j = 1; i > j; ++j) {
			if(suf[j + 1] >= j) {
				dp[i] = min(dp[i], dp[i - j] + b);
			}
		}
	}
	cout << dp[n];
		
	
	
	
	
	
	
		
	
    return 0;
}