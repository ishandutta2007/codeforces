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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n;	
	cin >> n;
	if(n < 100) {
		set<int> s;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++) {
					if(i+j+k<=n)
						s.insert(n + (4*i+9*j+49*k));
				}
		cout << s.size() << endl;
	} else {
		cout << 49*n-247 << endl;
	}
}