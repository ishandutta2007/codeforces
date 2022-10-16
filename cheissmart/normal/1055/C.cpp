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
#define int ll

const int INF = 1e9 + 7;

int l1, r1, t1, l2, r2, t2;

int go(int l) {
	int r = l + r2 - l2;
	return min(r1, r) - max(l, l1) + 1;
}

int32_t main()
{
	IO_OP;
	
	cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;
	int g = __gcd(t1, t2);
	int k = floor(1.*(l1 - l2) / g);
	int ll = l2 + k * g;
	cout << max(max(go(ll), go(ll+g)), 0ll) << endl;

}