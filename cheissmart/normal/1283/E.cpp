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

const int INF = 1e9 + 7, N = 200005;
int cnt[N], a[N], b[N], n;

int go_mx() {
	memset(cnt, 0, sizeof cnt);
	memset(a, 0, sizeof a);
	for(int i=1;i<=n;i++) 
		cnt[b[i]]++;
	for(int i=1;i<=n;i++) {
		for(int j=i-1;j<=i+1&&cnt[i];j++) {
			if(a[j] == 0) {
				a[j] = 1;
				cnt[i]--;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=n+1;i++)
		ans += a[i];
	return ans;
}

int go_mn() {
	memset(cnt, 0, sizeof cnt);
	memset(a, 0, sizeof a);
	for(int i=1;i<=n;i++) 
		cnt[b[i]]++;
	for(int i=1;i<=n;i++) {
		if(cnt[i]) {
			if(a[i-1] || a[i] || a[i+1]) continue;
			a[i+1] = 1;
		}
	}
	int ans = 0;
	for(int i=0;i<=n+1;i++)
		ans += a[i];
	return ans;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> b[i];
	cout << go_mn() << " " << go_mx() << endl;
}