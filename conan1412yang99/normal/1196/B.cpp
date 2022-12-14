#include <bits/stdc++.h>
#define MP make_pair
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9 + 7;

int32_t main()
{
	int q;
	cin >> q;
	while(q--) {
		int n, k, s = 0;
		cin >> n >> k;
		vi ans;
		for(int i=0;i<n;i++) {
			int t;
			cin >> t;
			s += t;
			if((s & 1) && ans.size() != k-1) {
				s = 0;
				ans.PB(i+1);
			}
		}
		if(s & 1)
			ans.PB(n);
		else {
			cout << "NO" << endl;
			continue;
		}
		if(ans.size() == k) {
			cout << "YES" << endl;
			for(int e:ans)
				cout << e << " ";
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}