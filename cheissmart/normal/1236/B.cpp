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

const int INF = 1e9 + 7, M = 1e9 + 7;

int pw(int a, int b) {
	if(b == 0) return 1;
	int t = pw(a, b/2);
	if(b&1) return t * t % M * a % M;
	else return t * t % M;
}

int32_t main()
{
	IO_OP;
	
	int n, m;	
	cin >> n>> m;
	cout << pw((pw(2, m)+M-1)%M, n) << endl;
}