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
	
	vi po, ne;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t >= 0)
			po.PB(t);
		else
			ne.PB(-t);
	}
	sort(po.begin(), po.end());
	sort(ne.begin(), ne.end());
	ll ans = 0;
	for(int i=0;i<po.size();i++) {
		ans += upper_bound(po.begin(), po.end(), 2*po[i]) - upper_bound(po.begin(), po.end(), po[i]); 
	}
	for(int i=0;i<ne.size();i++) {
		ans += upper_bound(ne.begin(), ne.end(), 2*ne[i]) - upper_bound(ne.begin(), ne.end(), ne[i]); 
	}
	for(int i=0;i<ne.size();i++) {
		ans += upper_bound(po.begin(), po.end(), 2*ne[i]) - lower_bound(po.begin(), po.end(), ne[i]); 
	}
	for(int i=0;i<po.size();i++) {
		ans += upper_bound(ne.begin(), ne.end(), 2*po[i]) - upper_bound(ne.begin(), ne.end(), po[i]); 
	}
	cout << ans << endl;
}