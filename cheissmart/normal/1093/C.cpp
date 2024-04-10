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

int main()
{
	IO_OP;
	
	int n;
	ll t;
	cin >> n >> t;
	vector<pair<ll, ll>> v;
	v.PB({0, t});
	for(int i=1;i<n/2;i++) {
		cin >> t;
		if(t == v.back().F + v.back().S) {
			v.PB(v.back());
		} else if(t > v.back().F + v.back().S) {
			v.PB({t-v.back().S, v.back().S});
		} else {
			v.PB({v.back().F, t-v.back().F});
		}
	}
	for(int i=0;i<n/2;i++)
		cout << v[i].F << " ";
	for(int i=n/2-1;i>=0;i--)
		cout << v[i].S << " ";
}