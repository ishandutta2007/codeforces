#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int maxh = 0, par[2001], height[2001];

int geth(int node) {
	if (height[node] != 0) return height[node];
	if (par[node] == -1) return height[node] = 1;
	return height[node]=geth(par[node])+1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	FOR(i,1,n+1) cin >> par[i];
	FOR(i,1,n+1) maxh = max(maxh,geth(i));
	cout << maxh;
}