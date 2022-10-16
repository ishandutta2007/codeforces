#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

string a[2];
int n;

bool dfs(int i, int j, int d) {
	if(i == 1 && j == n) return true;
	if(j >= n) return false;
	int p = a[i][j] <= '2';
	if(d == 0) {
		if(p == 1)
			return dfs(i, j+1, 0);
		else
			return dfs(i^1,j,1);
	} else {
		if(p == 1)
			return false;
		else 
			return dfs(i, j+1, 0);
	}
}

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		cin >> n;
		cin >> a[0] >> a[1];
		if(dfs(0, 0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}