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

int a[200005];

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i=0;i<n;i++)
			cin >> a[i];
		int mn = INF, ans = 0;
		for(int i=0;i<n-k;i++) {
			int c = a[i+k] - a[i];
			if(c < mn) {
				mn = c;
				ans = (a[i] + a[i+k]) / 2;
			}
		}
		cout << ans << endl;
	}
	
}