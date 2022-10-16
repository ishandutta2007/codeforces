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
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for(int i=1;i<=n;i++) {
		if(a[n] - a[i] == 0 || a[n] - a[i] == n - i) {
			cout << i << endl;
			return 0;
		}
	}
	
}