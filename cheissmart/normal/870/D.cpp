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

const int INF = 1e9 + 7, N = 10005;

int p0[N], b0[N], p[N], b[N];

signed main()
{	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "? " << 0 << " " << i << endl;
		cin >> p0[i];
	}
	for(int i = 0; i < n; i++) {
		cout << "? " << i << " " << 0 << endl;
		cin >> b0[i];
	}
	int cnt = 0;
	vi v;
	for(int i = 0; i < n; i++) {
		int p00 = i;
		for(int j = 0;j < n; j++) {
			b[j] = p0[j] ^ p00;
			p[b[j]] = j; 
		}
		if(p[0] != p00) continue;
		bool ok = true;
		for(int j = 0; j < n; j++) {
			if((p[0] ^ b[j]) != p0[j]) {
				ok = false;
			}
		}
		for(int j = 0; j < n; j++) {
			if((p[j] ^ b[0]) != b0[j]){
				ok = false;
			}
		}
		if(ok) {
			cnt++;
			if(v.empty()) {
				for(int i = 0;i < n;i++) v.PB(p[i]);
			}
		}
	}
	cout << "!" << endl;
	cout << cnt << endl;
	for(int e:v) cout << e<<" ";
		cout << endl;
}