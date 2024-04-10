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

bool adj[1003][1003];

signed main()
{
	IO_OP;
	
	int n, a, b;
	cin >> n >> a >> b;
	if((n == 2 || n == 3) && a == 1 && b == 1) {
		cout << "NO" << endl;
		return 0;
	}
	if(a != 1 && b != 1) {
		cout << "NO" << endl;
		return 0;
	}	
	cout << "YES" << endl;
	bool inv = false;
	if(b != 1) swap(a, b), inv = true;
	for(int i=a;i+1<=n;i++)
		adj[i][i+1] = adj[i+1][i] = true;
	if(inv) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i != j)
					adj[i][j] = !adj[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout << adj[i][j];
		cout << endl;
	}
	

}