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

const int INF = 1e9 + 7, N = 2e5 + 7;

int cnt[N], a[N];
vi pos[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		int t = a[i];
		t %= m;
		pos[t].PB(i);
		cnt[t]++;
	}
	int want = n / m;
	int ans = 0;
	vi free;
	for(int j = 0; j < 2; j++) {
		for(int i = 0; i < m; i++) {
			if(cnt[i] == want) continue;
			while(free.size() && cnt[i] < want) {
				ans += (i - a[free.back()] % m + m) % m;
				a[free.back()] += (i - a[free.back()] % m + m) % m;
				pos[i].PB(free.back());
				cnt[i]++;
				free.pop_back();
			}
			if(cnt[i] > want) {
				for(int k=0;k<cnt[i]-want;k++) {
					int e = pos[i].back();
					pos[i].pop_back();
					free.PB(e);
				}
				cnt[i] = want;
			}
		}
	}
	cout << ans << endl;
	for(int i=0;i<n;i++) cout << a[i] << " ";
	cout << endl;
}