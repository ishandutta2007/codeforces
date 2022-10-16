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

const int INF = 1e9 + 7;

int a[200005];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k ;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);	
	vi v;
	for(int i=0;i<n;i++) {
		while(v.size() && a[i] != v.back() && a[i] - v.back() <= k) v.pop_back();
		v.PB(a[i]);
	}
	cout << v.size() << endl;
	
}