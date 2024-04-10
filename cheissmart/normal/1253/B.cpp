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

int in[1000006];
int cnt;

signed main()
{
	IO_OP;
	
	int n, day = 1;
	cin >> n;
	vi v({-1});
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t > 0) {
			if(in[t] == day || in[t] == -day) {
				cout << -1 << endl;
				return 0;
			}
			in[t] = day;
			cnt++;
		} else {
			t = -t;
			if(in[t] != day) {				
				cout << -1 << endl;
				return 0;
			}
			in[t] = -day;
			cnt--;
		}
		if(cnt == 0) {
			v.PB(i);
			day++;
		}
	}
	if(cnt) {
		cout << -1 << endl;
		return 0;
	}
	cout << v.size() - 1 << endl;
	for(int i=1;i<v.size();i++) cout << v[i] - v[i-1] << " ";
}