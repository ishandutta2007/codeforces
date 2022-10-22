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
#define bignum vector <int>
 
 
using namespace std;
string s;
int lit[30];

int main() {
	ios;
	cin >> s;
	FOR(i, 0, 29)
		lit[i] = -1;
	FOR(i, 0, ss(s) - 1) {
		int c = s[i] - 'a';
		if(lit[c] == -1)
			lit[c] = i;
	}
	FOR(i, 0, ss(s) - 1) {
		int c = s[i] - 'a';
		bool win = 0;
		FOR(j, 0, c - 1) {
			if(lit[j] != -1 && i > lit[j])
				win = 1;
		}
		if(win)
			cout << "Ann\n";
		else
			cout << "Mike\n";
	}
	
	
	
	return 0;
}