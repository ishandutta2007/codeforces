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

const int INF = 1e9 + 7, N = 200005;

int a[N], ans[N];
pi b[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++)
		cin >> b[i].F, b[i].S = i;
	sort(a, a+n);
	sort(b, b+m);
	for(int i=0,j=0;i<n||j<m;) {
		if(j == m || (i < n && a[i] <= b[j].F)) i++;
		else {
			ans[b[j].S] = i;
			j++;
		}
	}
	for(int i=0;i<m;i++) cout << ans[i] << " ";
}