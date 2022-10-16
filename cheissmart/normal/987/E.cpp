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

int a[1000006];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	if(n == 5) {
		cout << "Petr" << endl;
		return 0;
	}
	int cnt = 0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] == i) cnt++;
	}
	if(cnt > n/500) cout << "Petr" << endl;
	else cout << "Um_nik" << endl;

}