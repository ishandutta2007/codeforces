#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005];

int32_t main()
{
	IO_OP;
	
	int n, s = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		s += a[i];
	}
	if(s & 1) {
		cout << "NO" << endl;
		return 0;
	}
	sort(a, a+n);
	if(a[n-1] > s - a[n-1]) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

}