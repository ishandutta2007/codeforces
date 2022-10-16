#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int ct[1024];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n>> k;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		ct[t]++;
	}
	int ans = 0, bb = 0;
	for(int i=1;i<=k;i++) {
		ans += ct[i] / 2 * 2;
		bb += ct[i] % 2;
	}
	ans += (bb+1)/2;
	
	cout << ans << endl;
	
}