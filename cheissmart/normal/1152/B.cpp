#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int x, ct = 0;
	cin >> x;
	vi v;
	for(int i=0;i<40;i++) {
		bool ok = 1;
		for(int j=0;x >> j;j++) {
			if(((x >> j) & 1) == 0)
				ok = 0;
		}
		if(ok) break;
		ct++;
		if(i & 1) {
			x++;
			continue;
		}
		int k;
		for(int j=0;x >> j;j++) {
			if(((x >> j) & 1) == 0)
				k = j;
		}
		k++;
		v.PB(k);
		k = (1 << k) - 1;
		x ^= k;
	}
	cout <<ct<< endl;
	for(int e:v) cout << e << " ";
	
}