#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[205], b[205];

int main()
{
	IO_OP;
	
	int n, d;
	cin >> n >> d;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		a[t]++, b[i] = t;
	}
	for(int i=1;i<205;i++)
		a[i] += a[i-1];
	int tot = a[204], ans = INF;
	for(int i=0;i<n;i++) {
		int cans = a[b[i]+d] - a[b[i]-1];
		ans = min(tot-cans, ans);
	}
	cout << ans << endl;
}