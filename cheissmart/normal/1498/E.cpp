#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 505;

int a[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	V<array<int, 3>> v;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			v.PB({abs(a[i] - a[j]), i, j});
		}
	}
	sort(ALL(v), greater<array<int, 3>>());
	for(auto p:v) {
		int i = p[1], j = p[2];
		if(a[i] > a[j]) swap(i, j);
		cout << "? " << j << " " << i << endl;
		string res;
		cin >> res;
		if(res == "Yes") return cout << "! " << i << " " << j << endl, 0;
	}
	cout << "! 0 0" << endl;

}