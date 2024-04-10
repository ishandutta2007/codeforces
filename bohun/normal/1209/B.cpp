#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
using namespace std;
using namespace __gnu_pbds;

const int nax = 1e5 + 111;

int n;
string s;
int t[nax][2];
int best = 0;
int w[nax];
int ile = 0;
int gao[nax];


int main() {
	cin >> n;
	cin >> s;
	int S = 0;
	FOR(i, 0, n - 1) {
		w[i] = s[i] - '0';
		S += w[i];
	}
	
	FOR(i, 0, n - 1) {
		cin >> t[i][0] >> t[i][1];
		swap(t[i][0], t[i][1]); // :(
		int x = (w[i] == 1 ? -1 : 1);
		for(int j = t[i][0]; j < nax - 1; j += t[i][1]) {
			gao[j] += x;
			x *= -1;
		}
	}
	ile = S;
	
	FOR(i, 1, nax - 1) {
		best = max(best, ile);
		ile += gao[i];
	}
	
	cout << best;
			
			
		
	
	
	return 0;
}