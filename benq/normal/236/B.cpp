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

const int MOD = 1<<30;
double PI = 4*atan(1);

vi prime;
vi di[101];
int ans = 0;

void genprime() {
	FOR(i,2,101) {
		bool p = 1;
		FOR(j,2,i) if (i % j == 0) p = 0;
		if (p) prime.pb(i);
	}	
	FOR(i,1,101) {
		di[i].resize(prime.size());
		int i1 = i;
		F0R(j,prime.size()) {
			while (i1 % prime[j] == 0) {
				i1 /= prime[j];
				di[i][j] ++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	genprime();
	int a,b,c; cin >> a >> b >> c;
	FOR(i,1,a+1) FOR(j,1,b+1) FOR(k,1,c+1) {
		int cur = 1;
		F0R(z,prime.size()) cur *= di[i][z]+di[j][z]+di[k][z]+1;
		ans = (ans+cur) % MOD;
	}
	cout << ans;
}