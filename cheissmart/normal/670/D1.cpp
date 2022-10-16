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

const int N = 1024;

int a[N], b[N];

int main()
{
	IO_OP;
	
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	int mn = INF, ans = 0;
	for(int i=0;i<n;i++)
		mn = min(mn, b[i] / a[i]);
	ans += mn;
	for(int i=0;i<n;i++)
		b[i] -= mn*a[i];
	while(true) {
		for(int i=0;i<n;i++) {
			if(b[i] >= a[i])
				b[i] -= a[i];
			else {
				k -= a[i] - b[i];
				b[i] = 0;
			}
		}
		if(k < 0) break;
		ans++;
	}
	cout << ans << endl;
}