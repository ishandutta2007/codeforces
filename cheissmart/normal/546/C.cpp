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
	
	int n, k;
	cin >> n;
	vi v1, v2;
	cin >> k;
	for(int i=0;i<k;i++) {
		int t;
		cin >> t;
		v1.PB(t);
	}
	cin >> k;
	for(int i=0;i<k;i++) {
		int t;
		cin >> t;
		v2.PB(t);
	}
	for(int ct=0;;ct++) {
		if(ct == v1.size()) {
			cout << ct << " " << 2 << endl;
			return 0;
		}
		if(ct == v2.size()) {
			cout << ct << " " << 1 << endl;
			return 0;
		}
		if(ct > 1000000) {
			cout << -1 << endl;
			return 0;
		}
		if(v1[ct] > v2[ct]) {
			v1.PB(v2[ct]);
			v1.PB(v1[ct]);
		} else {
			v2.PB(v1[ct]);
			v2.PB(v2[ct]);
		}
	}
}