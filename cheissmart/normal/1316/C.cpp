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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N], b[N];

signed main()
{
	IO_OP;
	
	int n, m, p;
	cin >> n >> m >> p;
	for(int i=0;i<n;i++) cin >> a[i], a[i] %= p;
	for(int i=0;i<m;i++) cin >> b[i], b[i] %= p;
	int i=0,j=0;
	while(i < n && a[i] == 0) i++;
	while(j < m && b[j] == 0) j++;
	cout << i + j << endl;
}