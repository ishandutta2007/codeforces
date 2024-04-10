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
int n;
string s;
map <char, int> mapka;

int main() {
	ios;
	cin >> n >> s;
	for(auto it: s)
		mapka[it] += 1;
	
	while(mapka['o'] > 0 && mapka['n'] > 0 && mapka['e'] > 0) {
		cout << 1 << " ";
		mapka['o'] -= 1;
		mapka['n'] -= 1;
		mapka['e'] -= 1;
	}
	while(mapka['z'] > 0 && mapka['e'] > 0 && mapka['r'] > 0 && mapka['o'] > 0) {
		cout << 0 << " ";
		mapka['z'] -= 1;
		mapka['e'] -= 1;
		mapka['r'] -= 1;
		mapka['o'] -= 1;
	}
	
	
	return 0;
}