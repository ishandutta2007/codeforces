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


int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		ll x = 1ll * a[0] * a[n-1];
		vi b;
		for(ll i=2;i*i<=x;i++) {
			if(x % i == 0) {
				b.PB(i);
				if(i*i!=x)
					b.PB(x/i);
			}
		}
		sort(b.begin(), b.end());
		if(a == b) cout << x << endl;
		else cout << -1 << endl;
	}		
}