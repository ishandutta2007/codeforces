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

int a[1024], a2[1024], b[1024];

int main()
{
	IO_OP;
	
	int n, ans1 = 0, ans2 = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		char c;
		cin >> c;
		a2[i] = a[i] = c - '0';
	}
	for(int i=0;i<n;i++) {
		char c;
		cin >> c;
		b[i] = c - '0';
	}
	sort(a, a+n);
	sort(a2, a2+n);
	sort(b, b+n);
	for(int i=0;i<n;i++) {
		bool ad = 1;
		for(int j=n-1;j>=0;j--) {
			if(a[j] <= b[i]) {
				a[j] = INF;
				ad = 0;
				break;
			}
		}
		if(ad) ans1++;
	}
	for(int i=0;i<n;i++) {
		for(int j=n-1;j>=0;j--) {
			if(a2[j] < b[i]) {
				ans2++;
				a2[j] = INF;
				break;
			}
		}
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
}