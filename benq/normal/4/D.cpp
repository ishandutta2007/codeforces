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

int n,w,h; 
int wid[5001], hei[5001];

bool done[5001];
int dp[5001], nex[5001];

int query(int x) {
	if (done[x]) return dp[x];
	dp[x] = 1, done[x] = 1, nex[x] = -1;
	F0R(i,n+1) if (i != x)
		if (wid[i]>wid[x] && hei[i]>hei[x] && query(i)+1>dp[x]) {
			dp[x] = query(i)+1;
			nex[x] = i;
		}
	return dp[x];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n+1) cin >> wid[i] >> hei[i];
	// F0R(i,n+1) cout << query(i) << " hi\n";
	cout << query(0)-1 << "\n";
	int cur = nex[0];
	while(cur != -1) {
		cout << cur << " ";
		cur = nex[cur];
	}
}