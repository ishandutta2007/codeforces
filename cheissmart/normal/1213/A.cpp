#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	int n;
	cin >> n;
	vi a, b;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t & 1) a.PB(t);
		else b.PB(t);
	}
	cout << min(a.size(), b.size()) << endl;
}