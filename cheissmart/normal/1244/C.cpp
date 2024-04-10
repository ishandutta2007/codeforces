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
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	for(int i=0;i<=100000;i++) if(p-i*d >= 0 && (p-i*d)%w == 0 && (p-i*d)/w+i <= n) {
		cout << (p-i*d)/w << " " << i << " " << n - (p-i*d)/w - i << endl;
		return 0;
	}
	cout << -1 << endl;
}