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

int a[202], b[202];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		char c;
		cin >> c;
		if(c == 'B') b[i] = a[i] = 1;
	}	
	vi v;
	for(int i=0;i<n-1;i++) {
		if(a[i] == 0) {
			a[i] = !a[i];
			a[i+1] = !a[i+1];
			v.PB(i);
		}
	}
	if(a[n-1] == 1)	{
		cout << v.size() << endl;
		for(int e:v) cout << e+1 << " ";
 	} else {
		vi v;
		for(int i=0;i<n-1;i++) {
			if(b[i]) {
				b[i] = !b[i];
				b[i+1] = !b[i+1];
				v.PB(i);
			}
		}
		if(b[n-1] == 0) {
			cout << v.size() << endl;
			for(int e:v) cout << e+1 << " ";
		} else {
			cout << -1 << endl;
		}

	}
	
}