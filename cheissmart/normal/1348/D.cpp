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

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi v;
		int sum = 0;
		for(int i = 0; i < 31; i++) {
			if(sum + (1LL << i) <= n) {
				sum += 1LL << i;
				v.PB(1LL << i);
			} else {
				if(n - sum > 0)
					v.PB(n - sum);
				break;
			}
		}
		sort(ALL(v));
		cout << (int)v.size() - 1 << endl;
		for(int i = 1; i < v.size(); i++) cout << v[i] - v[i-1] << " ";
		cout << endl;
	}
	
}