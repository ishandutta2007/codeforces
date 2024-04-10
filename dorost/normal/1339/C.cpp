#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, sum = 0, mx = 0, mex = 0;
		cin >> n;
		for (int i = 0; i <= n; i++)
			a[i] = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (i == 0){
				mx = a[i];
				continue;
			}
			mx = max(mx, a[i]);
			mex = max(mx - a[i], mex);
		}
		if (mex == 0)
			cout << 0 << endl;
		else
			cout << floor(log2(mex)) + 1 << endl;
	}
}