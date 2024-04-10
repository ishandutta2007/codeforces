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

int a[128], m[128];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	int type = 0, mx = -1;
	for(int i=0;i<128;i++) {
		if(m[i]) {
			type++;
			mx = max(mx, m[i]);
		}
	}
	cout << type * ((mx+k-1)/k*k) - n << endl;
}