#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

queue <int> q;
int n,m, ans=0, satisfied[100000];
vi edges[100000];

void dp() {
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		// cout << i << " " << q.size() << endl;
		if (edges[i].size() == 1) {
			satisfied[i] = 1;
			edges[edges[i][0]].erase(lb(edges[edges[i][0]].begin(), edges[edges[i][0]].end(), i));
			if (edges[edges[i][0]].size() == 1) q.push(edges[i][0]);
			edges[i].erase(edges[i].begin());
		}
	}
}

int main() {
	cin >> n >> m;
	
	F0R(i,m) {
		int x,y;
		cin >> x >> y;
		edges[x-1].pb(y-1);
		edges[y-1].pb(x-1);
	}
	F0R(i,n) sort (edges[i].begin(),edges[i].end());
	
	F0R(i,n) if (edges[i].size() == 1) q.push(i);
	dp();
	
	F0R(i,n) if (edges[i].size() == 0 && satisfied[i] == 0) ans++;
	cout << ans;
	return 0;
}