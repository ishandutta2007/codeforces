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

int a[100005];

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, r;
		cin >> n >> r;
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a, a+n);
		deque<int> dk;
		for(int i=0;i<n;i++)
			dk.PB(a[i]);
		int push = 0, ans = 0;
		while(dk.size()) {
			int bk = dk.back();
			while(dk.size() && dk.back() == bk) dk.pop_back();
			ans++;
			push += r;
			while(dk.size() && dk.front() <= push) dk.pop_front();
		}
		cout << ans << endl;
	}

}