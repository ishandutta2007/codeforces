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

int a[305];

int main()
{
	IO_OP;
	
	int n, p;
	cin >> p >> n;
	
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;
		t %= p;
		if(a[t]) {
			cout << i << endl;
			return 0;
		}
		a[t] = 1;
	}
	cout << -1 << endl;
	
}