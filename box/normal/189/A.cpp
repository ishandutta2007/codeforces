
// Problem : A. Cut Ribbon
// Contest : Codeforces Round #119 (Div. 2)
// URL : https://codeforces.com/problemset/problem/189/A
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ordered_set=tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

int dp[4005];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b, c; cin >> n >> a >> b >> c;
	rep1(i, 4000) dp[i] = -10000;
	iter(i, a, n+1) dp[i] = max(dp[i], dp[i-a]+1);
	iter(i, b, n+1) dp[i] = max(dp[i], dp[i-b]+1);
	iter(i, c, n+1) dp[i] = max(dp[i], dp[i-c]+1);
	cout << dp[n] << endl;
}