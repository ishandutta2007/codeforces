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

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,k; 
double ans = 0;
vi x;

void search(int cur) {
	if (cur == k) {
		F0R(i,n) FOR(j,i+1,n) if (x[i]>x[j]) ans++;
		return;
	}
	F0R(i,n) FOR(j,i,n) {
		F0R(k,n) if (i+k < j-k) swap(x[i+k],x[j-k]);
		search(cur+1);
		F0R(k,n) if (i+k < j-k) swap(x[i+k],x[j-k]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k; x.resize(n);
	F0R(i,n) cin >> x[i];
	search(0);
	F0R(i,k) ans /= (n*(n+1)/2);
	cout << fixed << setprecision(15) << ans;
}