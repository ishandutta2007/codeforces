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
 
int a[100005], b[100005], vis[100005];
 
int32_t main()
{
	IO_OP;
	
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0,j=0;i<n&&j<n;i++) {
		if(vis[a[i]]) continue;
		while(a[i] != b[j]) {
			vis[b[j]] = 1;
			j++, ans++;
		}
		j++;
	}
	cout << ans << endl;
}