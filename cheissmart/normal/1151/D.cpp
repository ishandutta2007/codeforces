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

int32_t main()
{
	IO_OP;
	
	int n, s = 0;
	cin >> n;
	vi v;
	for(int i=0;i<n;i++) {
		int a, b;
		cin >> a >> b;
		s += b * n - a;
		v.PB(a - b);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++)
		s += (n - i) * v[i];
	cout << s << endl;
	
}