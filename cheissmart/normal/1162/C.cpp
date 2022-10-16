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

const int INF = 1e9 + 7;

int a[100005], cnt[100005];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<k;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	set<int> s;
	set<pi> ans;
	for(int i=1;i<=n;i++)
		if(cnt[i] == 0) ans.insert({i, i});
	for(int i=1;i<n;i++) {
		int j = i + 1;
		if(cnt[j] == 0) ans.insert({i, j});
		if(cnt[i] == 0) ans.insert({j, i});
	}
	for(int i=0;i<k;i++) {
		cnt[a[i]]--;
		s.insert(a[i]);
		if(cnt[a[i]] == 0) {
			if(a[i]+1 <= n && s.count(a[i]+1) == 0)
				ans.insert({a[i]+1, a[i]});
			if(a[i]-1 >= 1 && s.count(a[i]-1) == 0)
				ans.insert({a[i]-1, a[i]});
		}
	}
	cout << ans.size() << endl;
}