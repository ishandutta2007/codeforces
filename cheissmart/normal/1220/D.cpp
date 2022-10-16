#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

vi G[100];
int a[200005];

int32_t main()
{
	IO_OP;
	
	int n, mx = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t, x = 0;
		cin >> a[i];
		int tt = a[i] & -a[i];
		while(tt) tt >>= 1, x++;
		G[x].PB(i);
		if(G[x].size() > G[mx].size()) mx = x;
	}	
	cout << n - G[mx].size() << endl;
	int j = 0;
	for(int i=0;i<n;i++)
		if(j < G[mx].size() && G[mx][j] == i) j++;
		else cout << a[i] << " ";
}