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

int a[50005];

int main()
{
	IO_OP;
	
	int n, t = 0, mn = INF;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		t += a[i];
		mn = min(mn, a[i]);
	}
	int ans = t;
	for(int i=0;i<n;i++) {
		for(int j=1;j*j<=a[i];j++) {
			if(a[i] % j == 0) {
				ans = min(ans, t-a[i]-mn+a[i]/j+j*mn);
			}
		}
	}
	cout << ans << endl;
}