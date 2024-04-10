#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	int pos = 1;
	for(int i = 1; i < n; i+=2) {
		a[pos] = i;
		a[n-i+pos] = i;
		pos++;
	}
	pos = n + 1;
	for(int i = 2; i < n; i+=2) {
		a[pos] = i;
		a[n-i+pos] = i;
		pos++;
	}
	for(int i = 1; i <= n * 2; i++) {
		if(a[i] == 0) a[i] = n;
		cout << a[i] << " ";
	}
}