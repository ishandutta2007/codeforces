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

int qry(int m) {
	cout << m << endl;
	int res;
	cin >> res;
	return res;
}

bool ok[30];

signed main()
{	
	int m, n;
	cin >> m >> n;

	for(int i=0;i<n;i++) {
		int t = qry(1);
		if(t == 0) return 0;
		if(t == 1) ok[i] = 1;
		else ok[i] = 0;
	}
	int l = 1, r = m;
	for(int i=n;i<60;i++) {
		int mm = (l + r) / 2;
		int res = qry(mm);
		if(res == 0) return 0;
		if(!ok[i%n]) res = -res;
		if(res == 1) l = mm + 1;
		else r = mm - 1;
	}
	
}