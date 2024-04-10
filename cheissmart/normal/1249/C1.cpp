#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, _n;
		cin >> n;
		_n = n;
		vi v;
		while(n) {
			v.PB(n%3);
			n /= 3;
		}
		v.PB(0);
		int j = -1;
		for(int i=0;i<v.size();i++)
			if(v[i] == 2)
				j = i;
		if(j == -1) {
			cout << _n << endl;
			continue;
		}
		while(v[j] != 0) j++;
		if(j == v.size()-1) {
			int ans = 1;
			for(int k=0;k<j;k++) ans *= 3;
			cout << ans << endl;
		} else {
			int p = 1,  ans = 0;
			for(int i=0;i<v.size()-1;i++) {
				if(i == j) ans += p;
				if(i > j) ans += p*v[i];
				p *= 3;
			}
			cout << ans << endl;
		}
	}	
	
}