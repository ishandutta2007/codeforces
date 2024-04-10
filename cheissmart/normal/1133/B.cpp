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

int a[105];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		a[t%k]++;
	}
	int ans = a[0]/2*2;
	for(int i=1;i<=(k-1)/2;i++) {
		ans += min(a[i], a[k-i])*2;
	}
	if(k % 2 == 0)
		ans += a[k/2]/2*2;
	cout << ans << endl;
}