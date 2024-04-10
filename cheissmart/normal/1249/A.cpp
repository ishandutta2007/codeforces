#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[102];

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, ans=1;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		for(int i=1;i<n;i++) if(a[i]==a[i-1]+1) ans = 2;
		cout << ans << endl;
	}
	
}