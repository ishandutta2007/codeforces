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

const int INF = 1e9 + 7, N = 1e6 + 6;

int p[N];

vi getP(int n) {
	vi ret;
	while(n != 1) {
		int q = p[n];
		while(n % q == 0)
			n /= q;
		ret.PB(q);
	}
	return ret;
}

int32_t main()
{
	IO_OP;

	for(ll i=2;i<N;i++) {
		if(p[i]) continue;
		p[i] = i;
		for(ll j=i*i;j<N;j+=i)
			p[j] = i;
	}

	int x2, ans = INF;
	cin >> x2;
	vi v = getP(x2);
	for(int q:v) {
		int m = x2 / q;
		for(int x1=(m-1)*q+1;x1<=x2;x1++) {
			vi t = getP(x1);
			int mx = *max_element(ALL(t));
			if(mx == x1) continue;
			int x0 = x1 - mx + 1; 
			ans = min(ans, x0);
		}
	}
	cout << ans << endl;

}