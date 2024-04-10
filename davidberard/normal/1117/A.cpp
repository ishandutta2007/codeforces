#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int mx = -1;
	int mxlen = 0;
	int len = 0;
	int lst = 0;
	int n;
	cin >> n;
	for(int i=0;i<n;++i) {
		int a;
		cin >> a;
		if(a > mx) {
			len = 1;
			lst = 1;
			mxlen = 1;
			mx = a;
		} else if(a == mx) {
			mxlen = max(++len, mxlen);
			lst = 1;
		} else {
			len = 0;
			lst = 0;
		}
	}
	cout << mxlen << endl;
	return 0;
}