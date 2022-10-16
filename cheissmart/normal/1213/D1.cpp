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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int n, k, a[55];

int go(int x) {
	vi v;
	for(int i=0;i<n;i++) {
		int t = a[i], c = 0;
		while(t > x)
			t /= 2, c++;
		if(t == x)
			v.PB(c);
		else 
			v.PB(INF);
	}
	sort(ALL(v));
	int ret = 0;
	for(int i=0;i<k;i++)
		ret += v[i];
	return ret;
}

int32_t main()
{
	IO_OP;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int ans = INF;
	for(int i=0;i<200005;i++)
		ans = min(ans, go(i));
	cout << ans << endl;	
}