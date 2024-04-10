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

pi a[300005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		a[i] = {t, i};
	}
	sort(a, a+n, greater<pi>());
	int mx, mn, k = INF;
	mx = mn = a[0].S;
	for(int i=1;i<n;i++) {
		k = min(k, min(a[i].F/abs(a[i].S-mx), a[i].F/abs(a[i].S-mn)));
		mx = max(mx, a[i].S);
		mn = min(mn, a[i].S);
	}
	cout << k << endl;
}