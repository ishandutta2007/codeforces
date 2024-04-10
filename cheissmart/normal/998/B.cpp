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

int a[102];

signed main()
{
	IO_OP;
	
	int n, b;
	cin >> n >> b;
	vi v;
	for(int i=0;i<n;i++) cin >> a[i];
	int l = 0, r = 0;
	for(int i=0;i<n-1;i++) {
		if(a[i]&1) r++;
		else l++;
		if(l == r) v.PB(abs(a[i]-a[i+1]));
	}
	sort(ALL(v));
	int cnt = 0, sum = 0;
	for(int i:v) {
		if(sum + i <= b) {
			sum += i;
			cnt++;
		}
	}
	cout << cnt << endl;
}