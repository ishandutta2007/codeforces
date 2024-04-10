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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e7 + 7;

int lp[N];

signed main()
{
	IO_OP;

	for(int i = 2; i < N; i++) {
		if(lp[i]) continue;
		lp[i] = i;
		for(ll j = (ll)i * i; j < N; j+=i)
			lp[j] = i;
	}
	
	int n;
	cin >> n;
	vi x, y;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			x.PB(-1), y.PB(-1);
			continue;
		}
		int p = lp[t], tt = t;
		while(t % p == 0) t /= p;
		if(t == 1) {
			x.PB(-1), y.PB(-1);
			continue;
		}
		x.PB(t), y.PB(tt/t);
	}	
	for(int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;

	
}