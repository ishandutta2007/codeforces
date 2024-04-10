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

int a[300005];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n;
	ll tot = 0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		tot += a[i];
	}
	sort(a, a+n);
	cin >> m;
	for(int i=0;i<m;i++) {
		int q;
		cin >> q;
		cout << tot - a[n-q] << endl;
	}
	
}