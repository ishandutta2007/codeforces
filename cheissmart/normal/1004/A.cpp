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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e15 + 7;
int n, d, a[102];

bool ok(int pos) {
	int mn = INF;
	for(int i=0;i<n;i++)
		mn = min(mn, abs(pos-a[i]));
	return mn == d;
}

signed main()
{
	IO_OP;
	
	cin >> n >> d;
	for(int i=0;i<n;i++)
		cin >> a[i];
	set<int> ans;
	for(int i=0;i<n;i++) {
		int pos = a[i] - d;
		if(ok(pos)) ans.insert(pos);
		pos = a[i] + d;
		if(ok(pos)) ans.insert(pos);
	}	
	cout << ans.size() << endl;
	
}