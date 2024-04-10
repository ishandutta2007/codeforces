// writer: piggydan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	cout << 10*n << ' ' << 9*n << endl;
}