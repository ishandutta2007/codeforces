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

int cnt[1000006], a[200005];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k, d;
		cin >> n >> d >> d;
		for(int i=0;i<n;i++)
			cin >> a[i];
		int c = 0;
		for(int i=0;i<d;i++) {
			cnt[a[i]]++;
			if(cnt[a[i]] == 1) c++;
		}
		int mn = c;
		for(int i=d;i<n;i++) {
			cnt[a[i-d]]--;
			if(cnt[a[i-d]] == 0) c--;
			cnt[a[i]]++;
			if(cnt[a[i]] == 1) c++;
			mn = min(mn, c);
		}
		cout <<mn << endl;
		for(int i=0;i<n;i++) cnt[a[i]] = 0;
	}

}