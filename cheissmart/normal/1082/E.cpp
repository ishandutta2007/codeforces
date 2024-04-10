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

int a[500005], ct[500005], mx[500005];

int main()
{
	IO_OP;
	
	int n, c;
	cin >> n >> c;
	int ans=-1e9;
	for(int i=0;i<n;i++)  {
		cin >> a[i];
		int of = -(ct[a[i]]-ct[c]);
		mx[a[i]] = max(mx[a[i]], of);
		ct[a[i]]++;
		int f = ct[a[i]]-ct[c];
		ans = max(ans, f+mx[a[i]]);
	}
	cout << ans + ct[c] << endl; 
}