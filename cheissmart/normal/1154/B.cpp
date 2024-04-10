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

int a[105];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	int sz = unique(a, a+n) - a;
	if(sz > 3) {
		cout << -1 << endl;
	} else if(sz == 1) {
		cout << 0 << endl;
	} else if(sz == 2) {
		cout << ((a[1] - a[0]) % 2 ? a[1] - a[0] : (a[1] - a[0])/2) << endl;
	} else {
		if(a[2] - a[1] == a[1] - a[0])
			cout << a[2] - a[1] << endl;
		else
			cout << -1 << endl;
	}
}