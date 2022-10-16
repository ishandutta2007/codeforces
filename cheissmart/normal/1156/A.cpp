#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[105];

int main()
{
	IO_OP;
	
	int n, ans;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(a[0] + a[1] == 5) {
		cout << "Infinite" << endl;
		return 0;
	} else {
		ans = max(a[0], a[1]) + 1;
	}
	if(n == 2) {
		cout << "Finite" << endl;
		cout << ans << endl;
	} else {
		bool inf = 0;
		for(int i=2;i<n;i++) {
			if(a[i]+a[i-1] == 5) {
				inf = 1;
				break;
			}
			if(a[i] == 2 && a[i-1] == 1 && a[i-2] == 3) {
				ans += 2;
			} else {
				ans += max(a[i], a[i-1]) + 1;
			}
		}
		if(inf) cout << "Infinite" << endl;
		else cout << "Finite\n" << ans << endl;
	}
}