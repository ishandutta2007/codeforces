#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

ld a[5005];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	ld mx = 0;
	for(int len=k;len<=n;len++) {
		for(int i=1;i+len-1<=n;i++) {
			int j = i + len - 1;
			mx = max(mx, (a[j]-a[i-1])/len);
		}
	}
	cout << fixed << setprecision(15) << mx << endl;

}