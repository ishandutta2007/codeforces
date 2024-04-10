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

int phi[1000006];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	if(k == 1) {
		cout << 3 << endl;
		return 0;
	}
	iota(phi, phi+n+1, 0);
	for(int i=2;i<=n;i++) {
		if(phi[i] == i) {
			phi[i]--;
			for(int j=2*i;j<=n;j+=i)
				phi[j] = phi[j] / i * (i - 1);
		}
	}
	k += 2;
	sort(phi+1, phi+n+1);
	cout << accumulate(phi+1, phi+k+1, 0LL) << endl;

}