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
 
const int INF = 1e9 + 7, N = 5e6 + 7;
 
pi yes[N];
int vis[N];
 
signed main()
{
	IO_OP;
 
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int sum = a[i] + a[j];
			if(vis[sum]) {
				cout << "YES\n";
				cout << yes[sum].F + 1 << " " << yes[sum].S + 1 << " " << i + 1 << " " << j + 1 << '\n';
				return 0;
			}
		}
		for(int j = 0; j < i; j++) {
			vis[a[i] + a[j]] = 1;
			yes[a[i] + a[j]] = {i, j};
		}
	}
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int diff = a[i] - a[j];
			int ii = i, jj = j;
			if(diff < 0)  {
				diff *= -1;
				swap(ii, jj);
			}
			if(vis[diff]) {
				cout << "YES\n";
				cout << ii + 1 << " " << yes[diff].S + 1 << " " << jj + 1 << " " << yes[diff].F + 1 << '\n';
				return 0;
			}
		}
		for(int j = 0; j < i; j++) {
			if(a[i] - a[j] >= 0) {
				vis[a[i] - a[j]] = 1;
				yes[a[i] - a[j]] = {i, j};
		 	} else {
				vis[a[j] - a[i]] = 1;
				yes[a[j] - a[i]] = {j, i};
		 	}
		}
	}
	cout << "NO\n";
 
}