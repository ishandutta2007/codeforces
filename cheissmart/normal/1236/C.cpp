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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

vi G[303];

int32_t main()
{
	IO_OP;
	int n, ct = 1;
	cin >> n;
	for(int i=0;i<n;i++) {
		if(i & 1) {
			for(int j=0;j<n;j++)
				G[j].PB(ct++);
		} else {
			for(int j=n-1;j>=0;j--)
				G[j].PB(ct++);
		}
	}
	for(int i=0;i<n;i++) {
		for(int e:G[i]) cout << e << " ";
		cout << endl;
	}
}