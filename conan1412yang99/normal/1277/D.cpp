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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

bool can[200005];
string t[200005];

void solve() {
	int n, c00=0, c11=0, c01=0, c10=0, cc01=0, cc10=0;
	unordered_map<string, int> ok;
	vi xx, yy;
	cin >> n;
	for(int i=0;i<n;i++) can[i] = 0;
	for(int i=0;i<n;i++) {
		cin >> t[i];
		if(t[i][0] == '0' && t[i].back() == '0') {
			c00++;
		} else if(t[i][0] == '1' && t[i].back() == '1') {
			c11++;
		} else {
			int j;
			if(j=ok[t[i]]) {
				can[j-1] = false;
			} else {
				can[i] = true;
			}
			// debug(j);
			reverse(ALL(t[i]));
			ok[t[i]] = i+1;
		}
	}
	for(int i=0;i<n;i++) {
		// cout <<i << ": " <<  can[i] << endl;
		if(t[i][0] != t[i].back()) {
			if(t[i][0] == '0') {
				if(can[i]) {
					cc01++;
					xx.PB(i+1);
				} else {
					c01++;
				}
			} else {
				if(can[i]) {
					cc10++;
					yy.PB(i+1);
				} else {
					c10++;
				}
			}
		}
	}
	int t01 = cc01 + c01, t10 = cc10 + c10;
	if(t01 + t10 == 0 && (c11 == 0 || c00 == 0)) {
		cout << 0 << endl;
		return;
	}
	if(t01 == 0 && t10 == 0) {
		if(c11 && c00) {
			cout << -1 << endl;
		} else {
			cout << 0 << endl;
		}
		return;
	}

	if(abs(t01 - t10) <= 1) {
		cout << 0 << endl;
		return;
	}
	if(t01 < t10) {
		swap(t01, t10);
		swap(c01, c10);
		swap(cc01, cc10);
		swap(xx, yy);
	}
	for(int i=1;i<=cc01;i++) {
		int x = t01 - i, y = t10 + i;
		if(x >= 0 && abs(x-y) <= 1) {
			cout << i << endl;
			for(int j=0;j<i;j++) cout << xx[j] << " ";
			cout << endl;
			return;
		}
	}
	cout << -1 << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();	
	
}