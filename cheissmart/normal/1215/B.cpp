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

int a[200005];

int32_t main()
{
	IO_OP;
	
	int n, c = 0, b = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int x = 0, y = 0;
	for(int i=0;i<n;i++) {
		if(a[i] > 0) x++;
		else {
			int z = y;
			y = x + 1;
			x = z;
		}
		c += x, b += y;
	}
	cout << b <<  " " << c << endl;
	
}