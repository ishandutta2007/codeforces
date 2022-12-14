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

const int INF = 1e9 + 7;

int a[100005];

int32_t main()
{
	IO_OP;
	
	int n, x = 0, y = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		y += a[i];
	}
	sort(a, a+n);
	for(int i=0;i<n/2;i++)
		x += a[i];
	y -= x;
	cout << x*x + y*y << endl;
}