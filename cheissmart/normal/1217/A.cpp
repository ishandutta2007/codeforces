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

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int s, i, e;
		cin >> s >> i >> e;
		int m = max((int)floor((i + e - s) / 2.) + 1, 0);
		cout << max(0, e - m + 1) << endl;
	}

}