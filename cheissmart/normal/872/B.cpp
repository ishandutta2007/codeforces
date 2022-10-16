#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 1e5 + 87;

int a[N], b[N], c[N];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	b[0] = a[0];
	for(int i=1;i<n;i++)
		b[i] = min(b[i-1], a[i]);
	c[n-1] = a[n-1];
	for(int i=n-2;i>=0;i--)
		c[i] = min(c[i+1], a[i]);
	if(k == 1) {
		cout << c[0] << endl;
		return 0;
	} 
	if(k == 2) {
		int mx = -INF;
		for(int i=0;i<n-1;i++)
			mx = max(mx, max(b[i], c[i+1]));
		cout << mx << endl;
		return 0;
	}
	int mx = -INF;
	for(int i=0;i<n;i++)
		mx = max(mx, a[i]);
	cout << mx << endl;
}