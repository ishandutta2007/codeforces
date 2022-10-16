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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int l[300005], r[300005], cnt[300005];

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cnt[i] = 0;
		vi a(n);
		for(int i=0;i<n;i++) {
			cin >> a[i];
			if(cnt[a[i]] == 0) l[a[i]] = i;
			r[a[i]] = i;
			cnt[a[i]]++;
		}
		sort(ALL(a));
		a.resize(n = unique(ALL(a))-a.begin());
		int c = 1, d = 1;
		for(int i=1;i<n;i++) {
			if(l[a[i]] > r[a[i-1]]) c++;
			else c = 1;
			d = max(d, c);
		}
		cout << n - d << endl;
	}	
	
}