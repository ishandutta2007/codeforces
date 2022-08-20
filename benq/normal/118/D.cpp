/*#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 100000000;
double PI = 4*atan(1);

int num[101][101][2];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n1,n2,k1,k2; cin >> n1 >> n2 >> k1 >> k2;
	num[0][0][0] = num[0][0][1] = 1;
	F0R(i,n1+1) F0R(j,n2+1) {
		if (i == 0 && j == 0) continue;
		FOR(k,1,k1+1) if (k <= i) {
			num[i][j][0] += num[i-k][j][1];
			// cout << "HI " << i << " " << j << " " << i-k << " " << j << "\n";
		}
		num[i][j][0] %= MOD;
		// cout << i << " " << j << " 0 " << num[i][j][0] << "\n";
		FOR(k,1,k2+1) if (k <= j) num[i][j][1] += num[i][j-k][0];
		num[i][j][1] %= MOD;
		// cout << i << " " << j << " 1 " << num[i][j][1] << "\n";
	}
	cout << (num[n1][n2][0]+num[n1][n2][1]) % MOD;
}