#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

string A = "sjfnb", B = "cslnb";

int a[100005];

int32_t main()
{
	IO_OP;
	
	int n, sm = 0;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		sm += a[i];
	}
	if(sm == 0) {
		cout << B << endl;
		return 0;
	}
	if(n == 1) {
		if(a[1] & 1)
			cout << A << endl;
		else
			cout << B << endl;
		return 0;
	}
	int ct = 0;
	sort(a+1, a+n+1);
	for(int i=1;i<n;i++) {
		if(a[i] == a[i+1]) {
			if(a[i] == 0) {
				cout << B << endl;
				return 0;
			}
			a[i]--;
			swap(A, B);
			break;
		}
	}
	for(int i=1;i<n;i++) {
		if(a[i] == a[i+1]) {
			cout << A << endl;
			return 0;
		}
	}
	a[0] = -1;
	for(int i=1;i<=n;i++) {
		ct += a[i] - a[i-1] - 1;
		a[i] = a[i-1] + 1;
	}
	if(ct & 1) {
		cout << A << endl;
	} else {
		cout << B << endl;
	}
}