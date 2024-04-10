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

int a[10004];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int mx = 0, ans = 0;
	for(int i=1;i<=n;i++) {
		mx = max(mx, a[i]);
		if(i >= mx) ans++;
	}
	cout << ans << endl;
}